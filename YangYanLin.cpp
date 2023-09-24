#include <iostream>

int main() {
    system("powershell.exe -ExecutionPolicy Bypass -File D:\\homework\\MyCode\\1.ps1");
    std::cout<<"Hello"<<'\n';
    system("pause");
    return 0;
}