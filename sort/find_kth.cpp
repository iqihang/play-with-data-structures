#include <iostream>

using namespace std;

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

bool FindKth(int arr[], int n, int k, int& res) {
    if (k < 1 || k > n) {
        return false;  // k值不合法
    }
    int low = 0, high = n - 1;
    while (low <= high) {
        int pivot = Partition(arr, low, high);
        if (pivot == k - 1) {
            res = arr[pivot];  // 找到第k小的元素，通过res返回
            return true;
        }
        if (pivot < k - 1) {
            low = pivot + 1;  // 第k小的元素在枢轴元素的右边
        } else {
            high = pivot - 1;  // 第k小的元素在枢轴元素的左边
        }
    }
    return false;
}

void TestFindKth(int arr[], int n, int k) {
    int res;
    if (FindKth(arr, n, k, res)) {
        printf("第%d小的元素是：%d\n", k, res);
    } else {
        printf("k值不合法\n");
    }
}

int main() {
    int arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    TestFindKth(arr0, 9, 1);
    TestFindKth(arr0, 9, 5);
    TestFindKth(arr0, 9, 9);
    TestFindKth(arr0, 9, 10);

    int arr1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    TestFindKth(arr1, 9, 1);
    TestFindKth(arr0, 9, 5);
    TestFindKth(arr1, 9, 9);
    TestFindKth(arr1, 9, 10);

    int arr2[] = {6, 8, 7, 1, 3, 5, 9, 4, 2};
    TestFindKth(arr2, 9, 1);
    TestFindKth(arr0, 9, 5);
    TestFindKth(arr2, 9, 9);
    TestFindKth(arr2, 9, 10);

    return 0;
}