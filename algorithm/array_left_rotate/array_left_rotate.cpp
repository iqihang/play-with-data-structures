#include <iostream>

using namespace std;

void Reverse(int r[], int from, int to) {
    while (from < to) {
        swap(r[from++], r[to--]);
    }
}

void LeftRotate(int r[], int n, int p) {
    Reverse(r, 0, p - 1);  // 逆置前p个元素
    Reverse(r, p, n - 1);  // 逆置后n-p个元素
    Reverse(r, 0, n - 1);  // 逆置所有元素
}

void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void TestLeftRotate(int arr[], int n, int p) {
    printf("test begin, n = %d, p = %d\n", n, p);
    PrintArray(arr, n);
    LeftRotate(arr, n, p);
    PrintArray(arr, n);
    printf("test end\n");
}

int main() {
    int arr0[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TestLeftRotate(arr0, sizeof(arr0) / sizeof(arr0[0]), 3);

    int arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TestLeftRotate(arr1, sizeof(arr1) / sizeof(arr1[0]), 1);

    int arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TestLeftRotate(arr2, sizeof(arr2) / sizeof(arr2[0]), 9);

    return 0;
}