#pragma once

#include <stdlib.h>
#include <iostream>

using namespace std;

typedef int ElemType;
typedef struct BSTNode {
    ElemType key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

// 在二叉排序树t中查找关键字为key的结点，递归实现
BSTree SearchBST(BSTree t, ElemType key) {
    if (!t) {
        return NULL;
    }
    if (t->key == key) {
        return t;
    }
    if (t->key > key) {
        return SearchBST(t->lchild, key);
    }
    return SearchBST(t->rchild, key);
}

// 在二叉排序树t中查找关键字为key的结点，非递归实现
BSTree SearchBST2(BSTree t, ElemType key) {
    while (t && t->key != key) {
        if (t->key > key) {
            t = t->lchild;  // 在左子树中查找
        } else {
            t = t->rchild;  // 在右子树中查找
        }
    }
    return t;
}

// 在二叉排序树t中插入一个关键字为key的结点，递归实现
bool InsertBST(BSTree& t, ElemType key) {
    if (!t) {
        t = (BSTree)malloc(sizeof(BSTNode));  // 申请新结点
        if (!t) {
            return false;
        }
        t->key = key;
        t->lchild = t->rchild = NULL;  // 初始化新结点
        return true;
    }
    if (t->key == key) {
        return false;  // 如果关键字已存在，插入失败
    }
    if (t->key > key) {
        return InsertBST(t->lchild, key);  // 插入到左子树中
    }
    return InsertBST(t->rchild, key);  // 插入到右子树中
}

// 在二叉排序树t中插入一个关键字为key的结点，非递归实现
bool InsertBST2(BSTree& t, ElemType key) {
    BSTree* p = &t;
    while (*p) {
        if ((*p)->key == key) {
            return false;  // 如果关键字已存在，插入失败
        }
        if ((*p)->key > key) {
            p = &(*p)->lchild;  // 在左子树中查找
        } else {
            p = &(*p)->rchild;  // 在右子树中查找
        }
    }
    *p = (BSTree)malloc(sizeof(BSTNode));  // 申请新结点
    if (!*p) {
        return false;
    }
    (*p)->key = key;
    (*p)->lchild = (*p)->rchild = NULL;  // 初始化新结点
    return true;
}

// 中序遍历二叉排序树t
void PrintBST(BSTree t) {
    if (t) {
        PrintBST(t->lchild);
        printf("%d ", t->key);
        PrintBST(t->rchild);
    }
}