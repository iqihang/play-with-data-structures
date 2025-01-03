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

// 递归先序遍历
void PreOrderVisit(BiTree t, void (*visit)(BiTree)) {
    if (!t) return;
    visit(t);
    PreOrderVisit(t->lchild, visit);
    PreOrderVisit(t->rchild, visit);
}

// 递归中序遍历
void InOrderVisit(BiTree t, void (*visit)(BiTree)) {
    if (!t) return;
    InOrderVisit(t->lchild, visit);
    visit(t);
    InOrderVisit(t->rchild, visit);
}

// 递归后序遍历
void PostOrderVisit(BiTree t, void (*visit)(BiTree)) {
    if (!t) return;
    PostOrderVisit(t->lchild, visit);
    PostOrderVisit(t->rchild, visit);
    visit(t);
}

// 非递归先序遍历
void PreOrderVisit2(BiTree t, void (*visit)(BiTree)) {
    stack<BiTree> s;
    while (t || !s.empty()) {
        if (t) {
            visit(t);       // 先访问当前子树的根结点
            s.push(t);      // 将当前子树的根结点入栈
            t = t->lchild;  // 优先访问当前子树的左子树
        } else {
            t = s.top();
            s.pop();        // 弹出最近访问子树的根结点
            t = t->rchild;  // 访问当前子树的右子树
        }
    }
}

// 非递归中序遍历
void InOrderVisit2(BiTree t, void (*visit)(BiTree)) {
    stack<BiTree> s;
    while (t || !s.empty()) {
        if (t) {
            s.push(t);      // 先将当前子树的根结点入栈
            t = t->lchild;  // 优先访问当前子树的左子树
        } else {
            t = s.top();
            s.pop();        // 弹出最近访问子树的根结点
            visit(t);       // 访问当前子树的根结点
            t = t->rchild;  // 访问当前子树的右子树
        }
    }
}

// 非递归后序遍历
void PostOrderVisit2(BiTree t, void (*visit)(BiTree)) {
    stack<BiTree> s;
    BiTree last = NULL;  // 记录最近访问过的结点
    while (t || !s.empty()) {
        if (t) {
            s.push(t);      // 先将当前子树的根结点入栈
            t = t->lchild;  // 优先访问当前子树的左子树
        } else {
            t = s.top();
            if (t->rchild && t->rchild != last) {
                t = t->rchild;  // 当前子树的右子树存在且未被访问过，访问当前子树的右子树
            } else {
                s.pop();   // 弹出最近访问子树的根结点
                visit(t);  // 访问当前子树的根结点
                last = t;  // 记录最近访问过的结点
                t = NULL;  // 置空，继续弹出栈顶结点
            }
        }
    }
}

// 层次遍历
void LevelOrderVisit(BiTree t, void (*visit)(BiTree)) {
    if (!t) {
        return;  // 空树直接返回
    }
    queue<BiTree> q;
    q.push(t);  // 根结点入队
    while (!q.empty()) {
        BiTree p = q.front();
        q.pop();   // 队头结点出队
        visit(p);  // 访问队头结点
        if (p->lchild) {
            q.push(p->lchild);  // 如果有左孩子，将左孩子入队
        }
        if (p->rchild) {
            q.push(p->rchild);  // 如果有右孩子，将右孩子入队
        }
    }
}