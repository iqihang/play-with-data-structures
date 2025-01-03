#include "sqlist.h"

bool ReverseList(SqList& l, int start, int end) {
    if (start < 0 || end >= l.length || start >= end) {
        return false;
    }
    for (int i = start, j = end; i < j; ++i, --j) {
        swap(l.data[i], l.data[j]);
    }
    return true;
}

void RightShift(SqList& l, int k) {
    k %= l.length;
    ReverseList(l, 0, l.length - 1);
    ReverseList(l, 0, k - 1);
    ReverseList(l, k, l.length - 1);
}

int main() {
    SqList la;

    ElemType a[] = {1, 2, 3, 4, 5, 6, 7};

    CreateList(la, a, 7);
    PrintList(la);

    RightShift(la, 2);
    PrintList(la);

    return 0;
}