#include <iostream>

#include "bitree.h"

void PrintElem(BiTree t) { printf("%c ", t->data); }

void TestBiTree(ElemType arr[], int n) {
    printf("test begin\n");

    BiTree root;
    LevelOrderCreateBiTree(root, arr, n);

    printf("先序遍历：\n");
    PreOrderVisit(root, PrintElem);
    printf("\n");
    PreOrderVisit2(root, PrintElem);
    printf("\n");

    printf("中序遍历：\n");
    InOrderVisit(root, PrintElem);
    printf("\n");
    InOrderVisit2(root, PrintElem);
    printf("\n");

    printf("后序遍历：\n");
    PostOrderVisit(root, PrintElem);
    printf("\n");
    PostOrderVisit2(root, PrintElem);
    printf("\n");

    printf("层序遍历：\n");
    LevelOrderVisit(root, PrintElem);
    printf("\n");

    printf("test end\n");
}

int main() {
    ElemType arr0[] = {};
    TestBiTree(arr0, 0);

    ElemType arr1[] = {'A'};
    TestBiTree(arr1, 1);

    ElemType arr2[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    TestBiTree(arr2, 7);

    ElemType arr3[] = {'A', 'B', 'C', '#', '#', 'D', 'E', '#',
                       'F', '#', '#', 'G', '#', '#', '#'};
    TestBiTree(arr3, 15);

    return 0;
}