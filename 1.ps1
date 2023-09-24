$apiKey = "9e29bfae5b5144d7b6a95321230507"  # 替换为你的天气 API 密钥

$city = "Guangzhou"  # 要查询的城市名称

# 构建 API 请求 URL
$url = "https://api.weatherapi.com/v1/current.json?key=$apiKey&q=$city"

# 发送 GET 请求获取天气数据
$weatherData = Invoke-RestMethod -Uri $url

# 提取感兴趣的天气信息
$location = $weatherData.location.name
$temperature = $weatherData.current.temp_c
$condition = $weatherData.current.condition.text

# 构建要保存到文件的文本内容
$text = @"
Location: $location
Temperature: $temperature
Condition: $condition
"@

# 将文本保存到文件
$text | Out-File -FilePath "1.txt"
