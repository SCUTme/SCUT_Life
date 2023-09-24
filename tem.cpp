#include<iostream>
#include<chrono>

#include <iostream>
#include <cstdlib>
#include <ctime>

const int ARRAY_SIZE = 250;

// 生成随机排列数组的函数
void generateRandomPermutation(int a[], int size) {
    // 使用当前时间作为随机数生成的种子
    srand(static_cast<unsigned>(time(0)));

    // 生成第一个元素，它可以是任意整数
    a[0] = rand();

    for (int i = 1; i < size; ++i) {
        int randomNum;
        bool isUnique;

        // 不断生成随机数，直到它不同于已生成的元素
        do {
            isUnique = true;
            randomNum = rand();
            
            // 检查是否与已生成的元素重复
            for (int j = 0; j < i; ++j) {
                if (randomNum == a[j]) {
                    isUnique = false;
                    break;
                }
            }
        } while (!isUnique);

        // 将不重复的随机数填入数组
        a[i] = randomNum;
    }
}
void generateRandomPermutation2(int a[], int size)
{
        // 使用当前时间作为随机数生成的种子
    srand(static_cast<unsigned>(time(0)));
    
}


int main()
{
    // 获取程序开始时间点
    auto start_time = std::chrono::high_resolution_clock::now();

    // 在这里执行您的程序代码
    // 例如，您可以执行一些任务或算法
    int a[ARRAY_SIZE];

    generateRandomPermutation(a, ARRAY_SIZE);

    // 输出随机排列数组
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << a[i] << " ";
    }
    // 获取程序结束时间点
    auto end_time = std::chrono::high_resolution_clock::now();

    // 计算程序运行时间
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    // 将运行时间输出到标准输出
    std::cout << "total: " << duration.count() << " ms" << std::endl;


    system("pause");

}