#include <iostream>

#include "bitree.h"

int Width(BiTree t) {
    if (!t) {
        return 0;
    }
    int width = 1;    // t不为空时，宽度至少为1
    BiTree last = t;  // 记录当前层的最后一个节点
    queue<BiTree> q;
    q.push(t);  // 根节点入队
    while (!q.empty()) {
        BiTree p = q.front();
        q.pop();  // 对头结点出队
        if (p->lchild) {
            q.push(p->lchild);  // 如果有左孩子，将左孩子入队
        }
        if (p->rchild) {
            q.push(p->rchild);  // 如果有右孩子，将右孩子入队
        }
        if (p == last) {  // 如果p是当前层的最后一个节点
            width = max(width, (int)q.size());  // 更新宽度
            last = q.back();  // 更新last为下一层的最后一个节点
        }
    }
    return width;
}

int Depth(BiTree t) {
    if (!t) {
        return 0;
    }
    return max(Depth(t->lchild), Depth(t->rchild)) + 1;
}

int Lush(BiTree t) { return Width(t) * Depth(t); }

void TestLush(ElemType arr[], int n) {
    printf("test begin\n");

    BiTree root;
    LevelOrderCreateBiTree(root, arr, n);
    printf("繁茂度为：%d\n", Lush(root));

    printf("test end\n");
}

int main() {
    ElemType arr0[] = {};
    TestLush(arr0, 0);

    ElemType arr1[] = {'A'};
    TestLush(arr1, 1);

    ElemType arr2[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    TestLush(arr2, 7);

    ElemType arr3[] = {'A', 'B', 'C', '#', '#', 'D', 'E', '#',
                       'F', '#', '#', 'G', '#', '#', '#'};
    TestLush(arr3, 15);

    return 0;
}