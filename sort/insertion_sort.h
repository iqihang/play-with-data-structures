#pragma once

// 直接插入排序
void InsertionSort(int arr[], int n) {
    int i, j;
    for (i = 1; i < n; ++i) {
        int cur = arr[i];  // 记录当前值
        for (j = i - 1; j >= 0 && arr[j] > cur; --j) {
            arr[j + 1] = arr[j];  // 大于当前值的元素后移一位
        }
        arr[j + 1] = cur;
    }
}