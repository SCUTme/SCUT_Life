#include <iostream>
#include <chrono>
using namespace std;
int main() {
    // 获取程序开始时间点
    auto start_time = std::chrono::high_resolution_clock::now();

    // 在这里执行您的程序代码
    // 例如，您可以执行一些任务或算法
    int sum=0,n=10;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i*i;j++)
        {
            for(int k=0;k<j;k++)
            {
                sum++;
            }
        }
    }
    cout<<sum;


    // 获取程序结束时间点
    auto end_time = std::chrono::high_resolution_clock::now();

    // 计算程序运行时间
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    // 将运行时间输出到标准输出
    std::cout <<'\n'<< "total: " << duration.count() << " ms" << std::endl;
    system("pause");
    return 0;
}
