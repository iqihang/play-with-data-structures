#include <iostream>

#include "bitree.h"

void PrintElem(BiTree t) { printf("%c ", t->data); }

void TestBiTree(ElemType arr[], int n) {
    printf("test begin\n");

    BiTree root;
    LevelOrderCreateBiTree(root, arr, n);

    auto print = [](BiTree t) { printf("%c ", t->data); };

    printf("先序遍历：\n");
    PreOrderVisit(root, PrintElem);
    printf("\n");
    PreOrderVisit2(root, print);
    printf("\n");

    printf("中序遍历：\n");
    InOrderVisit(root, PrintElem);
    printf("\n");
    InOrderVisit2(root, print);
    printf("\n");

    printf("后序遍历：\n");
    PostOrderVisit(root, PrintElem);
    printf("\n");
    PostOrderVisit2(root, print);
    printf("\n");

    printf("层序遍历：\n");
    LevelOrderVisit(root, PrintElem);
    printf("\n");

    printf("test end\n");
}

int main() {
    ElemType arr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    TestBiTree(arr, 7);

    return 0;
}