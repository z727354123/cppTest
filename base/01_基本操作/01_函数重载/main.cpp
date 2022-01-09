#include <iostream>
using namespace std;



//int sum(int i, int j) {
//    return i + j + 10;
//}
//
//
//
//int sum(int i, double j) {
//    return i * j;
//}


void 函数重载() {
//    cout << sum(1, 2) << endl;
//    cout << sum(2, 5.5) << endl;
}

void display(long num) {
    cout << num << endl;
}
void display(double num) {
    cout << num << " dip2" << endl;
}

void 二义性() {
//    display(10);
//  传入 int 找不到 int 参数方法,
// 但是 int 可以 转换成 double 或 long,
// 同时存在 double long 方法, 就产生 二义性

// 函数重载实现方式
// name mangling 或 name decoration 技术
// C++ 对符号名 (变量名/函数名) 进行改编 修饰
}


int main() {

    函数重载(); // C 语言不支持重载
    二义性();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
