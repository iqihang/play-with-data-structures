#include <stdio.h>

#define MAXNUM 200  // 待排序数组中元素的最大值，值域为[0, MAXNUM)

void BucketSort(int a[], int n) {
    if (a == NULL || n <= 0) {
        return;
    }
    int slots[MAXNUM] = {0};  // 用于记录每个元素出现的次数，初始化为0
    for (int i = 0; i < n; ++i) {
        ++slots[a[i]];  // 记录每个元素出现的次数
    }
    int j = 0;
    for (int i = 0; i < MAXNUM; ++i) {  // 遍历每个元素出现的次数
        while (slots[i]--) {  // 如果该元素出现了，则将其重新放入数组a中
            a[j++] = i;
        }
    }
}

void PrintArray(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void TestBucketSort(int a[], int n) {
    printf("test begin\n");
    PrintArray(a, n);
    BucketSort(a, n);
    PrintArray(a, n);
    printf("test end\n");
}

int main() {
    int n;

    // 测试1
    int a0[] = {};
    n = sizeof(a0) / sizeof(int);
    TestBucketSort(a0, n);

    // 测试2
    int a1[] = {1};
    n = sizeof(a1) / sizeof(int);
    TestBucketSort(a1, n);

    // 测试3
    int a2[] = {1, 2, 3, 4, 5};
    n = sizeof(a2) / sizeof(int);
    TestBucketSort(a2, n);

    // 测试4
    int a3[] = {5, 4, 3, 2, 1};
    n = sizeof(a3) / sizeof(int);
    TestBucketSort(a3, n);

    // 测试5
    int a4[] = {1, 2, 1, 3, 2, 1, 5, 2, 6, 2, 5, 7, 2};
    n = sizeof(a4) / sizeof(int);
    TestBucketSort(a4, n);

    return 0;
}