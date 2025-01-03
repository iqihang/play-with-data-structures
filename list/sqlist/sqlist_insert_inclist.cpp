#include "sqlist.h"

bool InsertIncList(SqList& va, ElemType x) {
    if (va.length == MAXSIZE) {
        return false;  // 顺序表满
    }
    int i;
    for (i = va.length - 1; i >= 0 && va.data[i] > x;
         --i) {  // 值大于x的元素循环右移，为插入位置腾出空间
        va.data[i + 1] = va.data[i];
    }
    va.data[i + 1] = x;  // 插入元素x到第i+1个位置
    ++va.length;
    return true;
}

int main() {
    SqList l;
    ElemType a[] = {1, 2, 3, 4, 6, 7, 8, 9};

    CreateList(l, a, 8);
    PrintList(l);

    InsertIncList(l, 10);  // 测试边界情况
    PrintList(l);

    InsertIncList(l, 0);  // 测试边界情况
    PrintList(l);

    InsertIncList(l, 5);  // 测试一般情况
    PrintList(l);

    return 0;
}