#pragma once

#include <stdlib.h>
#include <queue>
#include <stack>

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

// 非递归先序搜索(DFS)
BiTree PreOrderSearch(BiTree t, ElemType e, bool (*cmp)(BiTree, ElemType)) {
    stack<BiTree> s;
    while (t || !s.empty()) {
        if (t) {
            if (cmp(t, e)) {
                return t;  // 找到目标结点，返回
            }
            s.push(t);      // 将当前子树的根结点入栈
            t = t->lchild;  // 优先搜索当前子树的左子树
        } else {
            t = s.top();
            s.pop();        // 弹出最近搜索子树的根结点
            t = t->rchild;  // 搜索当前子树的右子树
        }
    }
    return NULL;
}

// 非递归中序搜索(DFS)
BiTree InOrderSearch(BiTree t, ElemType e, bool (*cmp)(BiTree, ElemType)) {
    stack<BiTree> s;
    while (t || !s.empty()) {
        if (t) {
            s.push(t);      // 先将当前子树的根结点入栈
            t = t->lchild;  // 优先搜索当前子树的左子树
        } else {
            t = s.top();
            s.pop();  // 弹出最近搜索子树的根结点
            if (cmp(t, e)) {
                return t;  // 找到目标结点，返回
            }
            t = t->rchild;  // 搜索当前子树的右子树
        }
    }
    return NULL;
}

// 非递归后序搜索(DFS)
BiTree PostOrderSearch(BiTree t, ElemType e, bool (*cmp)(BiTree, ElemType)) {
    stack<BiTree> s;
    BiTree last = NULL;  // 记录最近搜索过的结点
    while (t || !s.empty()) {
        if (t) {
            s.push(t);      // 先将当前子树的根结点入栈
            t = t->lchild;  // 优先搜索当前子树的左子树
        } else {
            t = s.top();
            if (t->rchild && t->rchild != last) {
                t = t->rchild;  // 当前子树的右子树存在且未被搜索过，搜索当前子树的右子树
            } else {
                s.pop();  // 弹出最近搜索子树的根结点
                if (cmp(t, e)) {
                    return t;  // 找到目标结点，返回
                }
                last = t;  // 记录最近搜索过的结点
                t = NULL;  // 置空，继续弹出栈顶结点
            }
        }
    }
    return NULL;
}

// 层次搜索(BFS)
BiTree LevelOrderSearch(BiTree t, ElemType e, bool (*cmp)(BiTree, ElemType)) {
    if (!t) {
        return NULL;  // 空树直接返回
    }
    queue<BiTree> q;
    q.push(t);  // 根结点入队
    while (!q.empty()) {
        BiTree p = q.front();
        q.pop();  // 队头结点出队
        if (cmp(p, e)) {
            return p;  // 找到目标结点，返回
        }
        if (p->lchild) {
            q.push(p->lchild);  // 如果有左孩子，将左孩子入队
        }
        if (p->rchild) {
            q.push(p->rchild);  // 如果有右孩子，将右孩子入队
        }
    }
    return NULL;
}