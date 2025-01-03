#include <iostream>

#include "bitree.h"

int Depth(BiTree t) {
    if (!t) {
        return 0;
    }
    return max(Depth(t->lchild), Depth(t->rchild)) + 1;
}

void TestDepth(ElemType arr[], int n) {
    printf("test begin\n");

    BiTree root;
    LevelOrderCreateBiTree(root, arr, n);
    printf("深度为：%d\n", Depth(root));

    printf("test end\n");
}

int main() {
    ElemType arr0[] = {};
    TestDepth(arr0, 0);

    ElemType arr1[] = {'A'};
    TestDepth(arr1, 1);

    ElemType arr2[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    TestDepth(arr2, 7);

    ElemType arr3[] = {'A', 'B', 'C', '#', '#', 'D', 'E', '#',
                       'F', '#', '#', 'G', '#', '#', '#'};
    TestDepth(arr3, 15);

    return 0;
}