#include <iostream>
#include <stack>

#include "bitree.h"

BiTree last;

bool GreaterThanLast(BiTree t) {
    if (last && last->data > t->data) {
        return false;
    }
    last = t;
    return true;
}

bool InOrderSearch(BiTree t, bool (*cmp)(BiTree)) {
    stack<BiTree> s;
    while (t || !s.empty()) {
        if (t) {
            s.push(t);      // 先将当前子树的根结点入栈
            t = t->lchild;  // 优先访问当前子树的左子树
        } else {
            t = s.top();
            s.pop();        // 弹出最近访问子树的根结点
            if (!cmp(t)) {  // 访问当前子树的根结点
                return false;
            }
            t = t->rchild;  // 访问当前子树的右子树
        }
    }
    return true;
}

void TestIsBST(ElemType arr[], int n) {
    printf("test begin\n");

    BiTree root;
    LevelOrderCreateBiTree(root, arr, n);

    last = NULL;
    if (InOrderSearch(root, GreaterThanLast)) {
        printf("是BST\n");
    } else {
        printf("不是BST\n");
    }

    printf("test end\n");
}

int main() {
    ElemType arr0[] = {};
    TestIsBST(arr0, 0);

    ElemType arr1[] = {'A'};
    TestIsBST(arr1, 1);

    ElemType arr2[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    TestIsBST(arr2, 7);

    ElemType arr3[] = {'A', 'B', 'C', '#', '#', 'D', 'E', '#',
                       'F', '#', '#', 'G', '#', '#', '#'};
    TestIsBST(arr3, 15);

    ElemType arr4[] = {'D', 'B', 'F', 'A', 'C', 'E', 'G'};
    TestIsBST(arr4, 7);

    return 0;
}