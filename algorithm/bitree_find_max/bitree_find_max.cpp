#include <iostream>
#include <string>

#include "bitree.h"

BiTree maxNode;

void UpdateMaxNode(BiTree t) {
    if (t->data > maxNode->data) {
        maxNode = t;
    }
}

void TestFindMaxNode(BiTree t) {
    printf("test begin\n");

    struct {
        string name;
        void (*visit)(BiTree, void (*)(BiTree));
    } testFunc[] = {{"先序遍历", PreOrderVisit},
                    {"中序遍历", InOrderVisit},
                    {"后序遍历", PostOrderVisit},
                    {"层序遍历", LevelOrderVisit}};

    for (int i = 0; i < sizeof(testFunc) / sizeof(testFunc[0]); ++i) {
        maxNode = t;
        printf("%s: ", testFunc[i].name.c_str());
        testFunc[i].visit(t, UpdateMaxNode);
        if (maxNode) {
            printf("最大值为: %c\n", maxNode->data);
        } else {
            printf("找不到最大值\n");
        }
    }

    printf("test end\n");
}

int main() {
    ElemType arr0[] = {};
    BiTree t0;
    LevelOrderCreateBiTree(t0, arr0, 0);
    TestFindMaxNode(t0);

    ElemType arr1[] = {'A'};
    BiTree t1;
    LevelOrderCreateBiTree(t1, arr1, 1);
    TestFindMaxNode(t1);

    ElemType arr2[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    BiTree t2;
    LevelOrderCreateBiTree(t2, arr2, 7);
    TestFindMaxNode(t2);

    return 0;
}