#include <iostream>

#include "bubble_sort.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"

struct {
    string name;
    void (*sort)(int arr[], int n);
} sort_methods[] = {{"直接插入排序", InsertionSort},
                    {"冒泡排序", BubbleSort},
                    {"快速排序", QuickSort},
                    {"选择排序", SelectionSort},
                    {"堆排序", HeapSort},
                    {"归并排序", MergeSort}};

void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void TestSort(int arr[], int n) {
    int arr_copy[100];
    for (int i = 0; i < n; ++i) {
        arr_copy[i] = arr[i];
    }
    printf("原始数组：\n");
    PrintArray(arr, n);
    for (int i = 0; i < sizeof(sort_methods) / sizeof(sort_methods[0]); ++i) {
        for (int j = 0; j < n; ++j) {
            arr[j] = arr_copy[j];
        }
        sort_methods[i].sort(arr, n);
        printf("%s：\n", sort_methods[i].name.c_str());
        PrintArray(arr, n);
    }
}

int main() {
    int arr0[] = {5, 2, 9, 1, 5, 6};
    TestSort(arr0, sizeof(arr0) / sizeof(arr0[0]));

    int arr1[] = {1, 2, 3, 4, 5, 6};
    TestSort(arr1, sizeof(arr1) / sizeof(arr1[0]));

    int arr2[] = {6, 5, 4, 3, 2, 1};
    TestSort(arr2, sizeof(arr2) / sizeof(arr2[0]));

    int arr3[] = {1, 1, 1, 1, 1, 1};
    TestSort(arr3, sizeof(arr3) / sizeof(arr3[0]));

    int arr4[] = {1, 2, 1, 2, 1, 2};
    TestSort(arr4, sizeof(arr4) / sizeof(arr4[0]));

    return 0;
}