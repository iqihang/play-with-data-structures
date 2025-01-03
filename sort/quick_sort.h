#pragma once

int Partition(int arr[], int low, int high) {
    int pivot = arr[low];  // 枢轴元素
    while (low < high) {
        // 从右往左找到第一个小于枢轴元素的元素
        while (low < high && arr[high] >= pivot) {
            --high;
        }
        arr[low] = arr[high];
        // 从左往右找到第一个大于枢轴元素的元素
        while (low < high && arr[low] <= pivot) {
            ++low;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

// 快速排序
void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = Partition(arr, low, high);  // 划分，得到枢轴元素的位置
        QuickSort(arr, low, pivot - 1);  // 对枢轴元素左边的子序列进行快速排序
        QuickSort(arr, pivot + 1, high);  // 对枢轴元素右边的子序列进行快速排序
    }
}

void QuickSort(int arr[], int n) { QuickSort(arr, 0, n - 1); }