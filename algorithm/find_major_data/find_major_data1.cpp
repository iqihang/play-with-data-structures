#include <iostream>

int FindMajorData(int a[], int n) {
    int* slots = new int[n + 1];    // 用于记录每个元素出现的次数
    for (int i = 0; i <= n; ++i) {  // 初始化slots数组
        slots[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        ++slots[a[i]];  // 统计每个元素出现的次数
    }
    int major = -1;
    for (int i = 0; i <= n; ++i) {
        if (slots[i] > n / 2) {  // 如果某个元素出现的次数大于n/2，即为major
            major = i;
            break;
        }
    }
    delete[] slots;  // 释放slots数组
    return major;
}

void PrintArray(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void TestFindMajorData(int a[], int n) {
    printf("test begin\n");
    PrintArray(a, n);
    int major = FindMajorData(a, n);
    printf("major = %d\n", major);
    printf("test end\n");
}

int main() {
    // 测试1
    int a0[] = {1};
    TestFindMajorData(a0, sizeof(a0) / sizeof(int));

    // 测试2
    int a1[] = {1, 0};
    TestFindMajorData(a1, sizeof(a1) / sizeof(int));

    // 测试3
    int a2[] = {1, 0, 1};
    TestFindMajorData(a2, sizeof(a2) / sizeof(int));

    // 测试4
    int a3[] = {1, 0, 1, 0, 1, 0, 1};
    TestFindMajorData(a3, sizeof(a3) / sizeof(int));

    // 测试5
    int a4[] = {1, 0, 1, 0, 1, 0, 0, 0};
    TestFindMajorData(a4, sizeof(a4) / sizeof(int));

    // 测试6
    int a5[] = {1, 0, 1, 2, 1, 3, 1, 0, 1};
    TestFindMajorData(a5, sizeof(a5) / sizeof(int));

    return 0;
}