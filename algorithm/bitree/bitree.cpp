#include <iostream>

#include "bitree.h"

void PrintElem(BiTree t) { printf("%c ", t->data); }

void TestBiTree(ElemType arr[], int n) {
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
        printf("%s: ", testFunc[i].name.c_str());
        testFunc[i].visit(root, PrintElem);
        printf("\n");
    }

    printf("test end\n");
}

int main() {
    ElemType arr0[] = {};
    TestBiTree(arr0, 0);

    ElemType arr1[] = {'A'};
    TestBiTree(arr1, 1);

    ElemType arr2[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    TestBiTree(arr2, 7);

    ElemType arr3[] = {'A', 'B', 'C', '#', '#', 'D', 'E', '#',
                       'F', '#', '#', 'G', '#', '#', '#'};
    TestBiTree(arr3, 15);

    return 0;
}