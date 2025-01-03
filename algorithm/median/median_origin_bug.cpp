#include <iostream>

using namespace std;

int median(int A[], int B[], int n) {
    // 分别表示序列 A 和 B 的首位数、末位数和中位数
    int s1 = 0, d1 = n - 1, m1, s2 = 1, d2 = n - 1, m2;
    while (s1 != d1 || s2 != d2) {
        // 当序列A或B首位数不等于末位数时即序列中不只有一个元素
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;  // 令m1和m2分别等于序列A、B中间位置对应的数值
        if (A[m1] == B[m2])
            return A[m1];  // 满足条件1A的中位数与B的中位数相等，返回此值
        if (A[m1] < B[m2]) {  // 满足条件 2，即A的中位数小于B的中位数
            if ((s1 + d1) % 2 == 0) {  // 若元素个数为奇数
                s1 = m1;  // 舍弃 A 中间点以前的部分且保留中间点
                d2 = m2;  // 舍弃 B 中间点以后的部分且保留中间点
            } else {      // 元素个数为偶数
                s1 = m1 + 1;  // 舍弃 A 中间点及中间点以前部分
                d2 = m2;  // 舍弃 B 中间点以后部分且保留中间点
            }
        } else {                       // 满足条件 3
            if ((s1 + d1) % 2 == 0) {  // 若元素个数为奇数
                d1 = m1;  // 舍弃 A 中间点以后的部分且保留中间点
                s2 = m2;  // 舍弃 B 中间点以前的部分且保留中间点
            } else {      // 元素个数为偶数
                d1 = m1 + 1;  // 舍弃 A 中间点以后部分且保留中间点
                s2 = m2;      // 舍弃 B 中间点及中间点以前部分
            }
        }
    }
    // 两个序列中只含一个元素时，较小者即为所求的中位数
    return A[s1] < B[s2] ? A[s1] : B[s2];
}

void PrintArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void TestMedian(int a[], int b[], int n) {
    printf("test begin\n");
    printf("a:\n");
    PrintArray(a, n);
    printf("b:\n");
    PrintArray(b, n);
    printf("median: %d\n", median(a, b, n));
    printf("test end\n");
}

int main() {
    int a0[] = {1};
    int b0[] = {0};
    TestMedian(a0, b0, 1);

    int a1[] = {0};
    int b1[] = {1};
    TestMedian(a1, b1, 1);

    int a2[] = {0, 0};
    int b2[] = {0, 0};
    TestMedian(a2, b2, 2);

    int a3[] = {0, 1};
    int b3[] = {0, 0};
    TestMedian(a3, b3, 2);

    int a4[] = {0, 0};
    int b4[] = {0, 1};
    TestMedian(a4, b4, 2);

    int a5[] = {1, 1};
    int b5[] = {0, 1};
    TestMedian(a5, b5, 2);

    int a6[] = {0, 1};
    int b6[] = {1, 1};
    TestMedian(a6, b6, 2);

    int a7[] = {0, 1, 2};
    int b7[] = {0, 1, 1};
    TestMedian(a7, b7, 3);

    int a8[] = {0, 1, 2};
    int b8[] = {0, 1, 2};
    TestMedian(a8, b8, 3);

    int a9[] = {0, 1, 2};
    int b9[] = {0, 2, 3};
    TestMedian(a9, b9, 3);

    int a10[] = {0, 1, 2};
    int b10[] = {2, 2, 3};
    TestMedian(a10, b10, 3);

    int a11[] = {0, 1, 2};
    int b11[] = {3, 4, 5};
    TestMedian(a11, b11, 3);

    int a12[] = {3, 4, 5};
    int b12[] = {0, 1, 2};
    TestMedian(a12, b12, 3);

    return 0;
}