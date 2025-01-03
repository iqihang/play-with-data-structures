#include "bst.h"

// 在二叉排序树t中插入一个关键字为key的结点，非递归实现
BSTree SearchInsertBST(BSTree& t, ElemType key) {
    BSTree* p = &t;
    while (*p) {
        if ((*p)->key == key) {
            return *p;  // 如果关键字已存在，返回该结点
        }
        if ((*p)->key > key) {
            p = &(*p)->lchild;  // 在左子树中查找
        } else {
            p = &(*p)->rchild;  // 在右子树中查找
        }
    }
    *p = (BSTree)malloc(sizeof(BSTNode));  // 申请新结点
    if (!*p) {
        return NULL;
    }
    (*p)->key = key;
    (*p)->lchild = (*p)->rchild = NULL;  // 初始化新结点
    return *p;
}

void TestSearchInsertBST(BSTree& t, ElemType key) {
    printf("test begin\n");
    printf("Insert %d:\nBST:\n", key);
    PrintBST(t);
    printf("\nNode: %p\n", SearchInsertBST(t, key));
    printf("test end\n");
}

int main() {
    BSTree t = NULL;

    TestSearchInsertBST(t, 5);
    TestSearchInsertBST(t, 3);
    TestSearchInsertBST(t, 7);
    TestSearchInsertBST(t, 2);
    TestSearchInsertBST(t, 4);
    TestSearchInsertBST(t, 7);

    return 0;
}