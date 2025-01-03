#include <iostream>
#include <random>

using namespace std;
#define MAXSIZE 10

void Rearrange(int a[], int n) {
    int low = 0, high = n - 1;
    int t = a[low];  // 暂存第一个元素，因为后面会被覆盖，不作为比较对象
    while (low < high) {
        while (low < high && a[high] >= 0) {  // 从后向前找第一个负数
            --high;
        }
        a[low] = a[high];                   // 负数放到前面
        while (low < high && a[low] < 0) {  // 从前向后找第一个非负数
            ++low;
        }
        a[high] = a[low];  // 非负数放到后面
    }
    a[low] = t;  // 最后将t放到最终位置
}

void Rearrange2(int a[], int n) {
    int low = 0, high = n - 1;
    while (low < high) {
        while (low < high && a[high] >= 0) {  // 从后向前找第一个负数
            --high;
        }
        while (low < high && a[low] < 0) {  // 从前向后找第一个非负数
            ++low;
        }
        swap(a[low], a[high]);  // 交换负数和非负数
    }
}

void PrintArray(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[MAXSIZE];
    random_device rd;                           // 获取随机数种子
    mt19937 gen(rd());                          // 随机数引擎
    uniform_int_distribution<> dis(-100, 100);  // 定义随机数的范围

    for (int i = 0; i < MAXSIZE; ++i) {
        a[i] = dis(gen);  // 生成随机数
    }
    PrintArray(a, MAXSIZE);
    Rearrange(a, MAXSIZE);
    PrintArray(a, MAXSIZE);

    return 0;
}