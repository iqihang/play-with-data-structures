#include "sqlist.h"

void BinarySearch(SqList& l, ElemType x) {
    int low = 0, high = l.length - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (l.data[mid] == x) {
            break;  // 找到元素，退出循环
        } else if (l.data[mid] < x) {
            low = mid + 1;  // x在mid的右边
        } else {
            high = mid - 1;  // x在mid的左边
        }
    }
    if (low > high) {  // 没有找到元素，此时l.data[high] < x < l.data[low]
        if (l.length == MAXSIZE) {
            return;  // 顺序表满
        }
        int i;
        for (i = l.length - 1; i >= low; --i) {  // 循环右移，为插入位置腾出空间
            l.data[i + 1] = l.data[i];
        }
        l.data[i + 1] = x;
        ++l.length;
        return;
    }
    if (mid != l.length - 1) {  // 找到元素，且不是最后一个元素
        swap(l.data[mid], l.data[mid + 1]);  // 与直接后继交换
    }
}

int main() {
    SqList l;
    l.length = 0;
    ElemType a[] = {1, 2, 3, 4, 6, 7, 8, 9};

    CreateList(l, a, 8);
    PrintList(l);

    BinarySearch(l, 10);  // 测试边界情况1：找不到元素 插入
    PrintList(l);

    BinarySearch(l, 10);  // 测试边界情况1：找得到元素 不交换
    PrintList(l);

    BinarySearch(l, 5);  // 测试一般情况1：找不到元素 插入
    PrintList(l);

    BinarySearch(l, 5);  // 测试一般情况2：找的到元素 交换
    PrintList(l);

    return 0;
}