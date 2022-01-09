#include <iostream>
// 方式1
//extern "C" {
//#include "sum.c"
//}

//#include "sum.h"
// 错误写法
// #include "sum.h" 没有 效果 定义的是 C++ , 找 SUM_int_int
// 正确写法
// 方式1
extern "C" {
#include "sum.h" // 项目有问题, 先不用
}



//extern "C"
void func() {
    std::cout << "func()" << std::endl;
}

/**
 * 方式 1
 * extern "C" 写在函数 前面, 告诉 使用 C 语言方式编译
 */
extern "C" void func(int a) {
    std::cout << "func(int a)" << std::endl;
}

/**
 * 方式 2
 * extern "C" { } 包裹一个 或 多个 函数
 */
 extern "C" {
     void func1() {
         std::cout << "func1()" << std::endl;
     }
//     void func1(int a) {
//         std::cout << "func1(int a)" << std::endl;
//     }
     void func2(int a) {
         std::cout << "func2(int a)" << std::endl;
     }
 }

 /**
  * 方式 3
  * 声明放前面, 实现放后面,
  * extern "C" 放在声明 部分
  *
  * extern "C" void test();
  *
    extern "C" {
        void test1();
        void test2();
    }
  */

extern "C" void test();
void test(int a);

int main() {

    func();
    func(2);
    func1();
    func2(2);
    test();
    test(2);
    std::cout << "Hello, World!" << std::endl;
    std::cout << sum(1, 20) << std::endl;
    std::cout << "Hello, World!" << std::endl;

    return 0;
}

void test() {
    std::cout << "test()" << std::endl;
}
void test(int a) {
    std::cout << "test(int a)" << std::endl;
}