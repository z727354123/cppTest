#include <iostream>
//#include "../02_extern/sum.h" // 测试 CMakeLists.txt 有没有错

void sout(int a = 10) {
    std::cout << "sout(int a) = " << a << std::endl;
}
// 注意点 1
// 默认值 只能从 右边开始 赋值, 减少 二义性
void sout(int a , int b = 20) {
    std::cout << "sout(int a, int b) a = " << a << std::endl;
    std::cout << "sout(int a, int b) b = " << b << std::endl;
}
// 注意点 2
// 同时有 声明 + 实现, 默认值只能 放在声明
// 跟顺序有关. 顺序在前, 又可以, 但是没有意义
// 因为 一般都是 直接 只引入 h 头文件
void soutTwo(int a, int b, int c);

void soutTwo(int a, int b = 20, int c = 30) {
    std::cout << "soutTwo a= " << a << std::endl;
    std::cout << "soutTwo b= " << b << std::endl;
    std::cout << "soutTwo c= " << c << std::endl;
}

// 注意点 3
// 默认参数 值, 可以是 常量, 全局符号(全局变量,函数名)
// 这里是指针类型函数 返回值类型(*变量名)(参数1类型, 参数2类型...)
int num = 50;
void soutThree (int a, int b = num, void(*func)(int) = sout , void(*func2)(int, int) = sout ) {
    std::cout << "soutThree a= " << a << std::endl;
    std::cout << "soutThree a= " << b << std::endl;
    func(3);
    func2(10, 30);
}

int main() {

//    std::cout << sum(1, 20) << std::endl; // 测试 CMakeLists.txt 有没有错

    sout();
    soutTwo(3);
    soutThree(12);

    std::cout << "Hello, World!" << std::endl;



    soutThree(12, 60);

    return 0;
}


#include <iostream>

using namespace std;

void foo() {
    class innerfunc {
    public:
        void operator()() {
            cout << "inner function object" << endl;
        }
    };
    innerfunc foo;
    foo();
    auto lambdafunc = [=]() -> void {
        cout << "inner lambda expression" << endl;
    };
    lambdafunc();
}