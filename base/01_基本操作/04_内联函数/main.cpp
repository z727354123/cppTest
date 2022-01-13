#include <iostream>

extern "C" {
#include "test.h"
}

// 内联函数
inline int sum(int a, int b) {
    return a + a + b + b;
}
// 宏
#define sum2(a, b) ((a) + (a) + (b) + (b))


void testTea();

int age = 10;

int &func() {
    return age;
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// 1. 引用测试
void refTest() {
    // 1. 返回 引用可以赋值
    std::cout << "-age = " << age << std::endl;
    func() = 30;
    std::cout << "-age = " << age << std::endl;
    // 2. 交换变量
    int a = 10;
    int b = 20;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    swap(a, b);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;


};

struct Stu {
    int age;
};
int getNum() {
    return 10;
}

void refUsefull();

void constTest() {
    const Stu str = {20};
    // 无法修改,
    // str.age = 30;

    Stu stu2 = {30};
    Stu *pStu = &stu2;
    // 可以修改
    pStu->age = 40;
    std::cout << "stu2.age = " << stu2.age << std::endl;
    std::cout << "stu2.& = " << &stu2 << std::endl;
    const Stu *pStu2 = &stu2;
    // 不能修改
    // pStu2->age = 50;
    // (*pStu2).age = 50;
    Stu stu3 = *pStu2;
    stu3.age = 60;
    std::cout << "stu2.age = " << stu2.age << pStu2->age << std::endl;
    std::cout << "stu3.age = " << stu3.age << std::endl;
    std::cout << "stu3.& = " << &stu3 << std::endl;
    stu2.age = 55;
    std::cout << "stu2.age = " << stu2.age << pStu2->age << std::endl;

    // 2. 5个指针区别
    int age = 10;
    const int *p0 = &age; // *p0 是常量, p0 不是常量
    int const *p1 = &age; // 同上
    // 不能通过 指针修改 所指向的内容, 可以修改 指针的指向
    int *const p2 = &age; // p2 是常量, *p2 不是常量
    // 不能修改 指针的指向, 但是可以修改 指针所指向的内容
    const int *const p3 = &age; // 都是常量
    int const *const p4 = &age; // 同上

    // 引用的本质就是指针
    // int  & const tmpAge = age;
    // 上一个版本不会错,
    // 代表就是 指针指向 不能改, 相当于 废话

    const int &rAge = age;
    // 不能通过 引用修改 所指向的内容

    // 结论: const 必须放在 & 符号的左边,
    // 才能算是 常引用



    int age2 = 20;
    p0 = &age2;
    // *p0 = 10;

    p1 = &age2;
    // *p1 = 23;

    // p2 = &age2;
    *p2 = 30;

    // p3 = &age2;
    // *p3 = 39;

    // p4 = &age2;
    // *p4 = 40;

    // 内容其实 都是 一致的
    std::cout << "*p0 = " << *p0 << std::endl;
    std::cout << "p0 = " << p0 << std::endl;
    std::cout << "&p0 = " << &p0 << std::endl;

    std::cout << "*p1 = " << *p1 << std::endl;
    std::cout << "p1 = " << p1 << std::endl;
    std::cout << "&p1 = " << &p1 << std::endl;

    std::cout << "*p2 = " << *p2 << std::endl;
    std::cout << "p2 = " << p2 << std::endl;
    std::cout << "&p2 = " << &p2 << std::endl;

    std::cout << "*p3 = " << *p3 << std::endl;
    std::cout << "p3 = " << p3 << std::endl;
    std::cout << "&p3 = " << &p3 << std::endl;

    std::cout << "*p4 = " << *p4 << std::endl;
    std::cout << "p4 = " << p4 << std::endl;
    std::cout << "&p4 = " << &p4 << std::endl;

    // 3. struct 指针
    Stu oldStu = {10};
    const Stu * student = &oldStu;

    // 这三个 都是 *stu
    // *student = oldStu;
    // (*student).age = 3;
    // student->age =3;

    student = &oldStu;

    // 4. 常引用
    int num = 10;
    const int &num2 = num;
    // num2 = 20;


    // 常引用的 特点
    // 1. 可以指向 临时数据
    const int &rNum = 30;
    std::cout << "rNum = " << rNum << std::endl;
    std::cout << "&rNum = " << &rNum << std::endl;
    // 2. 可以指向 表达式
    // int &rNum2 = age + age; // Non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
    const int &rNum2 = age + age;
    // 3. 可以指向 返回值
    const int &rNum3 = getNum();
    // 4. 指向不同 类型的 引用
    const double &rNum4 = age;
    const int &rInt4 = rNum4;
    std::cout << "age = " << age << std::endl;
    std::cout << "rNum4 = " << rNum4 << std::endl;
    std::cout << "rInt4 = " << rInt4 << std::endl;
    age = 33;
    // 当 常引用 指向了 不同类型的 数据是, 会产生 临时变量,
    // 即 引用指向的 并不是 初始化时 的 哪个变量
    std::cout << "age = " << age << std::endl;
    std::cout << "rNum4 = " << rNum4 << std::endl;
    std::cout << "rInt4 = " << rInt4 << std::endl;

    // 5用途
    refUsefull();

}
int sumTwo1(int &a, int &b) {
    return a + b;
}
int sumTwo2(const int &a, const int &b) {
    std::cout << "const a = " << a << " b = " << b << std::endl;
    return a + b;
}

int sumTwo3(const int &a, const int &b) {
    std::cout << "const a = " << a << " b = " << b << std::endl;
    return a + b;
}
int sumTwo3(int &a, int &b) {
    std::cout << "normal a = " << a << " b = " << b << std::endl;
    return a + b;
}

int sumTwo4(const int a, const int b) {
    std::cout << "const a = " << a << " b = " << b << std::endl;
    return a + b;
}
// int sumTwo4(int a, int b) {
//     std::cout << "normal a = " << a << " b = " << b << std::endl;
//     return a + b;
// }


int sumTwo5(int *a, int *b) {
    std::cout << "nor a = " << *a << " b = " << *b << std::endl;
    return *a + *b;
}
// sumTwo5(int *a, int *b) { 跟这个一模一样
// int sumTwo5( int * const a,  int * const b) {
//     std::cout << "const a = " << *a << " b = " << *b << std::endl;
//     return *a + *b;
// }
int sumTwo5(const int *a, const int *b) {
    std::cout << "const a = " << *a << " b = " << *b << std::endl;
    return *a + *b;
}

void refUsefull() {
    const int num1 = 10;
    const int num2 = 20;
    int num3 = 30;
    int num4 = 40;
    // 这里 的 引用形参 无法兼容 两者
    // sumTwo1(num1, num2); // No matching function for call to 'sumTwo1'
    // sumTwo1(30, 40);
    sumTwo1(num3, num4);

    // 这里可以
    sumTwo2(num3, num4);
    sumTwo2(num1, num2);
    sumTwo2(30, 40);
    // 可以构成重载
    sumTwo3(num3, num4); // 进的是 非 常引用
    sumTwo3(num1, num2);
    sumTwo3(30, 40); // 进的是常引用, 非常引用进不去的, 才到 常引用
    sumTwo3(num4, 40); // 进的是常引用, 非常引用进不去的, 才到 常引用
    // 普通函数 + const 无法 重载
    sumTwo4(num3, num4);
    sumTwo4(num1, num2);
    sumTwo4(30, 40);
    sumTwo4(num4, 40);
    // 试试指针 能不能 重载
    sumTwo5(&num1, &num2); // 1 只能 常量
    sumTwo5(&num3, &num4);
    sumTwo5(&num1, &num4); // 跟常引用 类似

}

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
    // 3. 引用用途
    refTest();
    // 4. 常量测试
    constTest();
    return 0;
}

void testTea() {
    // 老师例子
    int a = 10;
    int b = 20;
    int &ta = a;

    int *pa = &a;
    int *&tpa = pa;


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
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;


    long c = 100;
    int d = 200;
    int e = 400;
    int f = 500;;
    int g = 500;
    int h = 500;
    long *tp = &c;


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
