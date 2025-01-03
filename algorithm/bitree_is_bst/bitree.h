#pragma once

#include <stdlib.h>
#include <queue>

using namespace std;

typedef char ElemType;
typedef struct BTNode {
    ElemType data;
    struct BTNode *lchild, *rchild;
} BTNode, *BiTree;

// 层序创建二叉树
void LevelOrderCreateBiTree(BiTree& t, ElemType a[], int n) {
    if (n <= 0) {
        t = NULL;
        return;
    }
    queue<BiTree*> q;
    q.push(&t);
    for (int i = 0; i < n && !q.empty(); ++i) {
        BiTree* p = q.front();
        q.pop();
        if (a[i] != '#') {
            *p = (BiTree)malloc(sizeof(BTNode));
            (*p)->data = a[i];
            (*p)->lchild = (*p)->rchild = NULL;
            q.push(&((*p)->lchild));
            q.push(&((*p)->rchild));
        }
    }
}
