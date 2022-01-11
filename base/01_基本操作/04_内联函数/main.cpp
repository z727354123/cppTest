#include <iostream>
extern "C" {
#include "test.h"
}

// 内联函数
inline int sum (int a, int b) {
    return a + a + b + b;
}
// 宏
#define sum2(a, b) ((a) + (a) + (b) + (b))


void testTea();

int main() {

    std::cout << "Hello, World!" << std::endl;
    std::cout << sum(10, 30) << std::endl;
    // 1. 特点
    // inline 效果 等同于
    // std::cout << 10 + 30 << std::endl;
    // 直接将 函数调用 展开成 函数体代码
    // 2. 优点
    // 减少 函数调用 的开销
    // 3. 缺点
    // 会增大 代码的体积, 就是直接 copy 过去的
    // 4. 注意
    // 尽量不要 内联超过 10行 代码的 函数
    // inline 写在 函数声明 + 实现 最好, 虽然任意一个就有效, 但是为了便于同意
    // 5. 只是建议
    // inline 递归函数 或 代码量特别大, 编译器 并不会把他展开成 函数体代码



    // 1. 对比宏
    std::cout << sum2(20, 30) << std::endl;
    // 内联函数 多了 语法检测 + 函数特性
    // 函数特性测试
    if (true) {
        int a = 1;
        int b = 1;
        std::cout << sum(a++, b++) << std::endl;
        std::cout << sum(1, 1) << std::endl;
    }
    if (true) {
        int a = 1;
        int b = 1;
        std::cout << sum2(a++, b++) << std::endl;
    }
    if (true) {
        int a = 1;
        int b = 1;
        std::cout << a++ + a++ + b++ + b++ << std::endl;
    }

    // 1. 测试指针类型
    std::cout << "-------------------" << std::endl;
    test();

    // 2, 例子
    testTea();

    return 0;
}

void testTea() {
    // 老师例子
    int a = 10;
    int b = 20;
    int& ta = a;

    int* pa = &a;
    int*& tpa = pa;


    std::cout << "a = " << a << std::endl;
    std::cout << "&a = " << &a << std::endl;
    std::cout << "ta = " << ta << std::endl;
    std::cout << "&ta = " << &ta << std::endl;
    std::cout << "*pa = " << *pa << std::endl;
    std::cout << "pa = " << pa << std::endl;
    std::cout << "&pa = " << &pa << std::endl;
    std::cout << "*tpa = " << *tpa << std::endl;
    std::cout << "tpa = " << tpa << std::endl;
    std::cout << "&tpa = " << &tpa << std::endl;
    std::cout << "*&tpa = " << *&tpa << std::endl;




    tpa = &b;

    std::cout << "*pa = " << *pa << std::endl;
    std::cout << "pa = " << pa << std::endl;
    std::cout << "&pa = " << &pa << std::endl;
    std::cout << "*tpa = " << *tpa << std::endl;
    std::cout << "tpa = " << tpa << std::endl;
    std::cout << "&tpa = " << &tpa << std::endl;
    std::cout << "*&tpa = " << *&tpa << std::endl;

    *pa = 30;
    std::cout << "a = "  << a << std::endl;
    std::cout << "b = " << b << std::endl;


    long c = 100;
    int d = 200;
    int e = 400;
    int f = 500;;
    int g = 500;
    int h = 500;
    long* tp = &c;


    std::cout << "&c =  " << &c << std::endl;
    std::cout << "&d  =  " << &d << std::endl;
    std::cout << "&e =  " << &e << std::endl;
    std::cout << "&f =  " << &f << std::endl;
    std::cout << "&g =  " << &g << std::endl;
    std::cout << "&h =  " << &h << std::endl;

    std::cout << "*tp =  " << *tp << std::endl;
    std::cout << "tp  =  " << tp << std::endl;
    std::cout << "&tp =  " << &tp << std::endl;
    tp++;
    std::cout << "*tp =  " << *tp << std::endl;
    std::cout << "tp  =  " << tp << std::endl;
    std::cout << "&tp =  " << &tp << std::endl;




}
