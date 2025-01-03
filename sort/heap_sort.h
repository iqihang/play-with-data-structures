#pragma once

using namespace std;

// 堆调整，将以i为根的子树调整为最大堆
void MaxHeapify(int arr[], int n, int i) {
    int largest = i;         // 记录最大元素的下标
    int lchild = 2 * i + 1;  // 左孩子的下标
    int rchild = 2 * i + 2;  // 右孩子的下标
    if (lchild < n && arr[lchild] > arr[largest]) {
        largest = lchild;  // 更新最大元素的下标
    }
    if (rchild < n && arr[rchild] > arr[largest]) {
        largest = rchild;  // 更新最大元素的下标
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);   // 交换当前元素和最大元素
        MaxHeapify(arr, n, largest);  // 递归调整最大堆
    }
}

// 堆排序
void HeapSort(int arr[], int n) {
    // 构建最大堆，调用 MaxHeapify() n/2 次
    for (int i = n / 2 - 1; i >= 0; --i) {
        MaxHeapify(arr, n, i);
    }
    // 依次取出堆顶元素，放到数组末尾
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);   // 交换堆顶元素和末尾元素
        MaxHeapify(arr, i, 0);  // 调整最大堆
    }
}
