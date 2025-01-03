#include <iostream>

using namespace std;

int median(int a[], int b[], int n) {
    // al是左半部在a[]的最大下标，ar是右半部在a[]的最小下标；bl是左半部在b[]的最大下标，br是右半部在b[]的最小下标
    int al, ar, bl, br;
    // 以b[]为基准，在a[]上搜索al，al可能搜索不到(即b[]中最大元素小于a[]中的最小元素，中位数为b[n-1])
    int low = 0, high = n - 1;
    while (low <= high) {
        al = (low + high) / 2;  // al的取值范围为[0, n-1]
        ar = al + 1;
        bl = n - ar - 1;
        br = bl + 1;
        // 边界条件，在a[]上搜索到最后一个元素，此时ar、bl不合法，br为0
        if (al == n - 1) {
            return min(a[al], b[br]);
        }
        if (a[al] <= b[br] && b[bl] <= a[ar]) {
            return max(a[al], b[bl]);  // 找到左右半部的边界，返回较大的那个
        }
        if (a[al] > b[br]) {
            high = al - 1;
        } else {
            low = al + 1;
        }
    }
    return b[n - 1];
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