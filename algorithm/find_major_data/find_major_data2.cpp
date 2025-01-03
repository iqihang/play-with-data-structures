#include <iostream>

int FindMajorData(int a[], int n) {
    int major = a[0];  // 出现次数最多的元素候选者
    int cnt = 1;
    // 遍历数组，找到出现次数最多的元素候选者
    for (int i = 1; i < n; ++i) {
        if (a[i] == major) {
            ++cnt;
        } else {
            --cnt;
            if (cnt == 0) {
                major = a[i];
                cnt = 1;
            }
        }
    }
    cnt = 0;
    // 再次遍历数组，统计出现次数最多的元素的出现次数
    for (int i = 0; i < n; ++i) {
        if (a[i] == major) {
            ++cnt;
        }
    }
    if (cnt <= n / 2) {
        major = -1;  // 候选者出现次数小于等于n/2，不存在出现次数大于n/2的元素
    }
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