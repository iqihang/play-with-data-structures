#include <iostream>

#include "bitree.h"

void PrintElem(BiTree t) { printf("%c ", t->data); }
// 交换左右子树
void Exchange(BiTree t) { swap(t->lchild, t->rchild); }

void TestExchange(ElemType arr[], int n) {
    printf("test begin\n");

    BiTree root;
    LevelOrderCreateBiTree(root, arr, n);

    printf("先序遍历：\n");
    PreOrderVisit(root, PrintElem);
    printf("\n");

    PostOrderVisit2(root, Exchange);

    printf("交换后先序遍历：\n");
    PreOrderVisit(root, PrintElem);
    printf("\n");

    printf("test end\n");
}

int main() {
    ElemType arr0[] = {};
    TestExchange(arr0, 0);

    ElemType arr1[] = {'A'};
    TestExchange(arr1, 1);

    ElemType arr2[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    TestExchange(arr2, 7);

    ElemType arr3[] = {'A', 'B', 'C', '#', '#', 'D', 'E', '#',
                       'F', '#', '#', 'G', '#', '#', '#'};
    TestExchange(arr3, 15);

    return 0;
}