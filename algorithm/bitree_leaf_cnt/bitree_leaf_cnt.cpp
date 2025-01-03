#include <iostream>

#include "bitree.h"

int cnt = 0;
// 统计叶子节点个数的函数
void LeafCnt(BiTree t) {
    if (!t->lchild && !t->rchild) {
        ++cnt;
    }
}

void TestLeafCnt(ElemType arr[], int n) {
    printf("test begin\n");

    BiTree root;
    LevelOrderCreateBiTree(root, arr, n);

    struct {
        string name;
        void (*visit)(BiTree, void (*)(BiTree));
    } testFunc[] = {{"先序遍历", PreOrderVisit},
                    {"中序遍历", InOrderVisit},
                    {"后序遍历", PostOrderVisit},
                    {"层序遍历", LevelOrderVisit}};

    for (int i = 0; i < sizeof(testFunc) / sizeof(testFunc[0]); ++i) {
        cnt = 0;
        printf("%s: ", testFunc[i].name.c_str());
        testFunc[i].visit(root, LeafCnt);
        printf("%d\n", cnt);
    }

    printf("test end\n");
}

int main() {
    ElemType arr0[] = {};
    TestLeafCnt(arr0, 0);

    ElemType arr1[] = {'A'};
    TestLeafCnt(arr1, 1);

    ElemType arr2[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    TestLeafCnt(arr2, 7);

    ElemType arr3[] = {'A', 'B', 'C', '#', '#', 'D', 'E', '#',
                       'F', '#', '#', 'G', '#', '#', '#'};
    TestLeafCnt(arr3, 15);

    return 0;
}