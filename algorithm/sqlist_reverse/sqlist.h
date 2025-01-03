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

void PrintList(SqList l) {
    for (int i = 0; i < l.length; ++i) {
        printf("%d ", l.data[i]);
    }
    printf("\n");
}