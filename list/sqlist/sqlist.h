#pragma once

#include <iostream>

using namespace std;

#define MAXSIZE 100          // 数组的最大长度
typedef int ElemType;        // 数据类型的别名
typedef struct {             // 定义线性表结构体
    ElemType data[MAXSIZE];  // 线性表存储元素的数组
    int length;              // 记录线性表长度
} SqList;                    // 线性表的名称

// 由a中n个元素创建顺序表l
void CreateList(SqList& l, ElemType a[], int n) {
    l.length = 0;  // 初始化表长为0
    // 扫描数组a，将数组a中的元素依次赋值给线性表
    for (int i = 0; i < n; ++i) {
        l.data[l.length++] = a[i];
    }
}

// 查找数据元素e在表中的位置
// 查找成功，返回元素在表中的位置（从1开始计数）
// 查找失败，返回0
int FindByValue(SqList& l, ElemType e) {
    for (int i = 0; i < l.length; ++i) {
        if (l.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

// 在顺序表l中第i个位置插入元素e
// 插入成功，返回true
// 插入失败，返回false
bool ListInsert(SqList& l, int i, ElemType e) {
    if (l.length == MAXSIZE) {
        return false;  // 顺序表满
    }
    if (i < 1 || i > l.length + 1) {
        return false;  // 插入位置不合法
    }
    for (int j = l.length; j >= i; --j) {  // 循环右移，为插入位置腾出空间
        l.data[j] = l.data[j - 1];
    }
    l.data[i - 1] = e;  // 插入元素e到第i个位置
    ++l.length;         // 插入元素后，表长增加1
    return true;
}

// 在顺序表l中第i个位置删除元素，并用e返回
// 删除成功，返回true
// 删除失败，返回false
bool ListDelete(SqList& l, int i, ElemType& e) {
    if (l.length == 0) {
        return false;  // 顺序表为空
    }
    if (i < 1 || i > l.length) {
        return false;  // 删除位置不合法
    }
    e = l.data[i - 1];                    // 用e返回被删除的元素
    for (int j = i; j < l.length; ++j) {  // 从删除位置开始循环覆盖前面的元素
        l.data[j - 1] = l.data[j];
    }
    --l.length;  // 删除元素后，表长减少1
    return true;
}

// 按值查找，删除顺序表中第一个值为e的元素
// 删除成功，返回true
// 删除失败，返回false
bool ListlocalDelete(SqList& l, ElemType e) {
    int i;
    for (i = 0; i < l.length && l.data[i] != e; ++i);  // 查找元素e的位置
    if (i >= l.length) {
        return false;  // 元素不存在
    }
    for (int j = i; j < l.length; ++j) {  // 从删除位置开始循环覆盖前面的元素
        l.data[j - 1] = l.data[j];
    }
    --l.length;  // 删除元素后，表长减少1
    return true;
}

void PrintList(SqList l) {
    for (int i = 0; i < l.length; ++i) {
        printf("%d ", l.data[i]);
    }
    printf("\n");
}