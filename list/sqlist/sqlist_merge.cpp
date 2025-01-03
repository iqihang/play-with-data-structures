#include <iostream>

using namespace std;

#define MAXSIZE 100
typedef int ElemType;
typedef struct {
    ElemType* elem;  // 存储空间的基地址
    int length;      // 当前长度
    int listsize;    // 当前分配的存储容量
} SqList;

// 由a中n个元素创建顺序表L
void CreateList(SqList& L, ElemType a[], int n) {
    L.elem = new ElemType[MAXSIZE];  // C++11之前new失败会抛出异常
    L.length = 0;
    L.listsize = MAXSIZE;
    // 扫描数组a，将数组a中的元素依次赋值给线性表
    for (int i = 0; i < n; ++i) {
        L.elem[L.length++] = a[i];
    }
}

void MergeList(SqList& A, SqList& B, SqList& C) {
    // 初始化空表C
    C.elem = new ElemType[A.length + B.length];
    C.length = 0;
    C.listsize = A.length + B.length;
    int i = 0, j = 0;
    // 将A和B中的元素按从小到大的顺序合并到C中
    while (i < A.length && j < B.length) {
        C.elem[C.length++] = A.elem[i] <= B.elem[j] ? A.elem[i++] : B.elem[j++];
    }
    // 处理A中剩余的元素
    while (i < A.length) {
        C.elem[C.length++] = A.elem[i++];
    }
    // 处理B中剩余的元素
    while (j < B.length) {
        C.elem[C.length++] = B.elem[j++];
    }
}

void PrintList(SqList l) {
    for (int i = 0; i < l.length; ++i) {
        printf("%d ", l.elem[i]);
    }
    printf("\n");
}

int main() {
    SqList A, B, C;

    ElemType a[] = {1, 3, 5, 7, 9};
    ElemType b[] = {2, 4, 6, 8, 10};

    CreateList(A, a, 5);
    CreateList(B, b, 5);

    MergeList(A, B, C);

    PrintList(A);
    PrintList(B);
    PrintList(C);

    return 0;
}