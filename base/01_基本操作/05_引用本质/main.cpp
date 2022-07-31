#include <iostream>
extern "C" {
#include "tmp.h"
}

int main() {

    // 1, 引用的本质
    // 就是指针
    // 只是编译器 削弱了 他的功能
    // 所以 = 弱化了 的 指针
    // = 一个引用 占用 一个指针的 大小

    // 反汇编查看方法 disas
    int age = 20;
    int &rage = age;
    rage = 30;


    std::cout << "Hello, World!" << std::endl;
    int arr[3] ;
    std::cout << " arr[0] = " << arr[0] << std::endl;
    std::cout << " arr[1] = " << arr[2] << std::endl;
    std::cout << " arr[2] = " << arr[2] << std::endl;

    testTmp();

    return 0;
}
