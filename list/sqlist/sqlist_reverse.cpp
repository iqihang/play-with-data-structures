#include "sqlist.h"

void ReverseList(SqList& l) {
    for (int i = 0, j = l.length - 1; i < j; ++i, --j) {
        swap(l.data[i], l.data[j]);
    }
}

bool ReverseList(SqList& l, int start, int end) {
    if (start < 0 || end >= l.length || start >= end) {
        return false;
    }
    for (int i = start, j = end; i < j; ++i, --j) {
        swap(l.data[i], l.data[j]);
    }
    return true;
}

int main() {
    SqList la, lb;

    ElemType a[] = {1, 3, 5, 7, 9, 11};
    ElemType b[] = {2, 4, 6, 8, 10};

    CreateList(la, a, 6);
    PrintList(la);
    ReverseList(la);
    PrintList(la);

    CreateList(lb, b, 5);
    PrintList(lb);
    ReverseList(lb, 0, 2);
    PrintList(lb);

    return 0;
}