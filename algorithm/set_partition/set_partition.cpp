#include <iostream>

#include "set.h"

// 将数组a[low...high]划分为两个子数组a[low...pos-1]和a[pos+1...high]
// 其中a[pos]是枢轴元素，a[low...pos-1]中的元素都小于等于a[pos]，a[pos+1...high]中的元素都大于等于a[pos]
// 返回枢轴元素的下标
int Partition(int a[], int low, int high) {
    int pivot = a[low];  // 选取a[low]作为枢轴元素
    while (low < high) {
        // 从high开始向前搜索，找到第一个小于pivot的元素
        while (low < high && a[high] >= pivot) {
            --high;
        }
        a[low] = a[high];
        // 从low开始向后搜索，找到第一个大于pivot的元素
        while (low < high && a[low] <= pivot) {
            ++low;
        }
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void SetPartition(Set& a, Set& a1, Set& a2) {
    int low = 0, high = a.size - 1;
    int pos = Partition(a.data, low, high);  // pos表示一趟Partition后的枢轴位置
    // 当pos等于a.size / 2时，说明已经找到了枢轴元素的位置
    while (pos != a.size / 2) {
        if (pos < a.size / 2) {
            low = pos + 1;  // 如果pos小于a.size / 2，则枢轴位置在pos的右边
        } else {
            high = pos - 1;  // 如果pos大于a.size / 2，则枢轴位置在pos的左边
        }
        pos = Partition(a.data, low, high);
    }
    for (int i = 0; i < pos; ++i) {
        a1.data[a1.size++] = a.data[i];
    }
    for (int i = pos; i < a.size; ++i) {
        a2.data[a2.size++] = a.data[i];
    }
}

void TestSetPartition(int arr[], int n) {
    printf("test begin\n");

    Set a, a1, a2;
    InitSet(a);
    InitSet(a1);
    InitSet(a2);

    CreateSet(a, arr, n);
    printf("a: ");
    PrintSet(a);

    SetPartition(a, a1, a2);
    printf("a1: ");
    PrintSet(a1);
    printf("a2: ");
    PrintSet(a2);

    printf("test end\n");
}

int main() {
    int a0[] = {};
    TestSetPartition(a0, 0);

    int a1[] = {1};
    TestSetPartition(a1, 1);

    int a2[] = {-1, 3, 9, 0, -5, -20, -3, 4, 0, 8, -12, 7};
    TestSetPartition(a2, 12);

    int a3[] = {-1, 3, 9, 0, -5, -20, -3, 4, 0, 8, -12, 7, 10};
    TestSetPartition(a3, 13);

    int a4[] = {-1, 3, -3, 10, 4, 0, 8, -12, 7, 9, 0, -5, -20, 1, 5, -10, 20};
    TestSetPartition(a4, 16);

    return 0;
}