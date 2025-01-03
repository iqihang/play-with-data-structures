#include <iostream>

#include "bitree.h"

// 判断两棵树是否互为镜像
bool Mirror(BiTree t1, BiTree t2) {
    if (!t1 && !t2) {
        return true;
    }
    if (!t1 || !t2) {
        return false;
    }
    return t1->data == t2->data && Mirror(t1->lchild, t2->rchild) &&
           Mirror(t1->rchild, t2->lchild);
}

bool Symmertric(BiTree t) {
    if (!t) {
        return true;
    }
    return Mirror(t, t);
}

void TestSymmertric(ElemType arr[], int n) {
    printf("test begin\n");

    BiTree root;
    LevelOrderCreateBiTree(root, arr, n);

    printf("是否对称：%s\n", Symmertric(root) ? "true" : "false");

    printf("test end\n");
}

int main() {
    ElemType arr0[] = {};
    TestSymmertric(arr0, 0);

    ElemType arr1[] = {'A'};
    TestSymmertric(arr1, 1);

    ElemType arr2[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    TestSymmertric(arr2, 7);

    ElemType arr3[] = {'A', 'B', 'C', '#', '#', 'D', 'E', '#',
                       'F', '#', '#', 'G', '#', '#', '#'};
    TestSymmertric(arr3, 15);

    ElemType arr4[] = {'A', 'B', 'B', 'D', 'E', 'E', 'D'};
    TestSymmertric(arr4, 7);

    return 0;
}