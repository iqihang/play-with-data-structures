#pragma once

void Merge(int arr[], int low, int mid, int high) {
    int i = low;                         // 左半部分的起始下标
    int j = mid + 1;                     // 右半部分的起始下标
    int* tmp = new int[high - low + 1];  // 创建临时数组
    int k = 0;                           // 临时数组的起始下标
    // 合并两个有序数组
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];  // 将左半部分的元素放入临时数组
        } else {
            tmp[k++] = arr[j++];  // 将右半部分的元素放入临时数组
        }
    }
    while (i <= mid) {
        tmp[k++] = arr[i++];  // 将左半部分剩余的元素放入临时数组
    }
    while (j <= high) {
        tmp[k++] = arr[j++];  // 将右半部分剩余的元素放入临时数组
    }
    for (int i = 0; i < k; ++i) {
        arr[low + i] = tmp[i];  // 将临时数组中的元素复制回原数组
    }
    delete[] tmp;  // 释放临时数组的内存
}

// 归并排序
void MergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;     // 计算中间下标
        MergeSort(arr, low, mid);       // 递归排序左半部分
        MergeSort(arr, mid + 1, high);  // 递归排序右半部分
        Merge(arr, low, mid, high);     // 合并两个有序数组
    }
}

void MergeSort(int arr[], int n) { MergeSort(arr, 0, n - 1); }