#include <iostream>

#include "bitree.h"

int MinDepth(BiTree t) {
    if (!t) {
        return 0;
    }
    return min(MinDepth(t->lchild), MinDepth(t->rchild)) + 1;
}

void TestMinDepth(ElemType arr[], int n) {
    printf("test begin\n");

    BiTree root;
    LevelOrderCreateBiTree(root, arr, n);
    printf("最小深度为：%d\n", MinDepth(root));

    printf("test end\n");
}

int main() {
    ElemType arr0[] = {};
    TestMinDepth(arr0, 0);

    ElemType arr1[] = {'A'};
    TestMinDepth(arr1, 1);

    ElemType arr2[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    TestMinDepth(arr2, 7);

    ElemType arr3[] = {'A', 'B', 'C', '#', '#', 'D', 'E', '#',
                       'F', '#', '#', 'G', '#', '#', '#'};
    TestMinDepth(arr3, 15);

    return 0;
}