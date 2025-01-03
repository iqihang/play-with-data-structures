#include "sqlist.h"

void ReverseList(SqList& l) {
    for (int i = 0, j = l.length - 1; i < j; ++i, --j) {
        swap(l.data[i], l.data[j]);
    }
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
    ReverseList(lb);
    PrintList(lb);

    return 0;
}