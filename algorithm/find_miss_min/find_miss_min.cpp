#include <iostream>

int FindMissMin(int a[], int n) {
    bool* b = new bool[n];  // 标记数组，用于标记1到n中的每个数字是否出现过
    for (int i = 0; i < n; ++i) {
        b[i] = false;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0 && a[i] <= n) {  // a[i]在[1, n]范围内，标记为出现过
            b[a[i] - 1] = true;
        }
    }
    int i = 0;
    while (i < n && b[i]) {  // 遍历标记数组，找到第一个未出现的数字
        ++i;
    }
    delete[] b;
    return i + 1;
}

void PrintArray(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void TestFindMissMin(int a[], int n) {
    printf("test begin\n");
    PrintArray(a, n);
    printf("miss min = %d\n", FindMissMin(a, n));
    printf("test end\n");
}

int main() {
    int a0[] = {1};
    TestFindMissMin(a0, sizeof(a0) / sizeof(int));

    int a1[] = {1, 0, -2, 6, 3};
    TestFindMissMin(a1, sizeof(a1) / sizeof(int));

    int a2[] = {1, 2, 3, 4, 5};
    TestFindMissMin(a2, sizeof(a2) / sizeof(int));

    int a3[] = {1, -2, 5, 0, -9, 7};
    TestFindMissMin(a3, sizeof(a3) / sizeof(int));

    int a4[] = {-9, -7, 0, -3, -1};
    TestFindMissMin(a4, sizeof(a4) / sizeof(int));

    return 0;
}