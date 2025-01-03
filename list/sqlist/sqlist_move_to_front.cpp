#include "sqlist.h"

void MoveToFront(SqList& va, ElemType x) {
    int i = va.length - 1;
    for (int j = va.length - 1; j >= 0; --j) {
        if (va.data[j] != x) {
            va.data[i--] = va.data[j];  // 非x元素右移
        }
    }
    while (i >= 0) {
        va.data[i--] = x;  // 将x元素移到最前面
    }
}

int main() {
    SqList l;
    ElemType a[] = {6, 2, 3, 4, 6, 7, 8, 6};

    CreateList(l, a, 8);
    PrintList(l);

    MoveToFront(l, 6);  // 测试一般情况+边界数据
    PrintList(l);

    MoveToFront(l, 8);  // 测试一般情况
    PrintList(l);

    MoveToFront(l, 1);  // 测试特殊情况
    PrintList(l);

    return 0;
}