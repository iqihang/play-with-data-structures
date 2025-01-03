#pragma once

#include <stdlib.h>
#include <iostream>

using namespace std;

typedef int ElemType;
typedef struct BSTNode {
    ElemType key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

// 中序遍历二叉排序树t
void PrintBST(BSTree t) {
    if (t) {
        PrintBST(t->lchild);
        printf("%p: %d ", t, t->key);
        PrintBST(t->rchild);
    }
}