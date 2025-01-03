#include <iostream>

#include "bitree.h"

// 判断t的左右孩子是否包含有e元素
bool HasChild(BiTree t, ElemType e) {
    if ((t->lchild && t->lchild->data == e) ||
        (t->rchild && t->rchild->data == e)) {
        return true;
    }
    return false;
}

void TestFindParent(BiTree t, ElemType e) {
    printf("test begin\n");

    BiTree p;

    struct {
        string name;
        BiTree (*search)(BiTree, ElemType, bool (*)(BiTree, ElemType));
    } testFunc[] = {
        {"先序搜索", PreOrderSearch},
        {"中序搜索", InOrderSearch},
        {"后序搜索", PostOrderSearch},
        {"层序搜索", LevelOrderSearch},
    };

    for (int i = 0; i < sizeof(testFunc) / sizeof(testFunc[0]); ++i) {
        printf("%s: ", testFunc[i].name.c_str());
        p = testFunc[i].search(t, e, HasChild);
        if (p) {
            printf("双亲结点为: %c\n", p->data);
        } else {
            printf("找不到双亲结点\n");
        }
    }

    printf("test end\n");
}

int main() {
    ElemType arr0[] = {};
    BiTree r0;
    LevelOrderCreateBiTree(r0, arr0, 0);
    TestFindParent(r0, 'A');

    ElemType arr1[] = {'A'};
    BiTree r1;
    LevelOrderCreateBiTree(r1, arr1, 1);
    TestFindParent(r1, 'A');
    TestFindParent(r1, 'B');

    ElemType arr2[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    BiTree r2;
    LevelOrderCreateBiTree(r2, arr2, 7);
    TestFindParent(r2, 'A');
    TestFindParent(r2, 'B');
    TestFindParent(r2, 'G');
    TestFindParent(r2, 'F');

    return 0;
}