#pragma once

int SeqSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            return i;  // 找到key，返回下标
        }
    }
    return -1;  // 未找到key，返回-1
}

int BinarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;  // 计算中间位置
        if (arr[mid] == key) {
            return mid;  // 找到key，返回下标
        }
        if (arr[mid] < key) {
            low = mid + 1;  // 如果key存在，一定在后半部分
        } else {
            high = mid - 1;  // 如果key存在，一定在前半部分
        }
    }
    return -1;  // 未找到key，返回-1
}