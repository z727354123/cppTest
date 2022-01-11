#include <stdio.h>
#include "test.h"

void test() {

    int a = 10;
    int b = 20;
    int* pA = &a;
    int** ppA = &pA;

    printf("a = %d \n", a);
    printf("pA = %d \n", pA);
    printf("*pA = %d \n", *pA);
    printf("ppA = %d \n", ppA);
    printf("*ppA = %d \n", *ppA);
    printf("**ppA = %d \n", **ppA);

    // C 语言 跟 go 类似

    // 但是 GO 不支持 指针运算, 需要 unsafe 包 支持
    // 数组
    int arr[5] = {1, 2, 3, 4, 5};

    // arr 数组名代表数组首元素的地址
    // arr 数组名代表数组首元素的地址
    printf("arr -> %p\n", arr);
    printf("&arr -> %p\n", &arr);
    printf("*arr -> %p\n", *arr);
// &arr[0] 代表数组首元素的地址
    printf("&arr[0] -> %p\n", &arr[0]);
    printf("*&arr[0] -> %p\n", *&arr[0]);
    printf("*&arr[4] -> %p\n", *&arr[4]);
    printf("arr[4] -> %p\n", arr[4]);
// &arr 代表整个数组 arr 的首地址
    printf("&arr -> %p\n", &arr);
    // 运行程序可以发现 arr 和 &arr 的输出值是相同的，但是它们的意义完全不同。
    //
    //首先数组名 arr 作为一个标识符，是 arr[0] 的地址，从 &arr[0] 的角度去看就是一个指向 int 类型的值的指针。
    //
    //而 &arr 是一个指向 int[5] 类型的值的指针。
    //
    //可以进一步对其进行指针偏移验证

        // C
    // 指针偏移
    printf("arr+1 -> %p\n", arr + 1);
    printf("&arr+1 -> %p\n", &arr + 1);

    // arr+1 : arr 是一个指向 int 类型的值的指针，因此偏移量为 1*sizeof(int)
    // arr+1 : &arr 是一个指向 int[5] 的指针，它的偏移量为 1*sizeof(int)*5
    printf("*(arr + 4) -> %p\n", *(arr + 4));





}
