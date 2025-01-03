#include "sqlist.h"

int main() {
    SqList l;

    ElemType a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    CreateList(l, a, 9);
    PrintList(l);

    return 0;
}