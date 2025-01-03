#pragma once

using namespace std;

// 选择排序
void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int min = i;  // 记录最小元素的下标
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min]) {
                min = j;  // 更新最小元素的下标
            }
        }
        swap(arr[i], arr[min]);  // 交换当前元素和最小元素
    }
}