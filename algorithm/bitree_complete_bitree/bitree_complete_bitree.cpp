#include <iostream>

#include "bitree.h"

// 判断是否为完全二叉树
bool CompleteBiTree(BiTree t) {
    queue<BiTree> q;
    q.push(t);  // 根结点入队
    while (!q.empty()) {
        BiTree p = q.front();
        q.pop();  // 队头结点出队
        if (!p) {
            break;  // 发现第一个空结点，跳出循环
        }
        q.push(p->lchild);  // 左孩子入队
        q.push(p->rchild);  // 右孩子入队
    }
    // 判断队列中是否还有非空结点
    while (!q.empty()) {
        BiTree p = q.front();
        q.pop();
        if (p) {
            return false;  // 发现非空结点，不是完全二叉树
        }
    }
    return true;
}

void TestCompleteBiTree(ElemType arr[], int n) {
    printf("test begin\n");

    BiTree root;
    LevelOrderCreateBiTree(root, arr, n);

    if (CompleteBiTree(root)) {
        printf("是完全二叉树\n");
    } else {
        printf("不是完全二叉树\n");
    }

    printf("test end\n");
}

int main() {
    ElemType arr0[] = {};
    TestCompleteBiTree(arr0, 0);

    ElemType arr1[] = {'A'};
    TestCompleteBiTree(arr1, 1);

    ElemType arr2[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    TestCompleteBiTree(arr2, 7);

    ElemType arr3[] = {'A', 'B', 'C', '#', '#', 'D', 'E', '#',
                       'F', '#', '#', 'G', '#', '#', '#'};
    TestCompleteBiTree(arr3, 15);

    return 0;
}