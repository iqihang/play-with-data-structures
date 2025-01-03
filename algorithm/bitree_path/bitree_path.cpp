#include <iostream>
#include <stack>

#include "bitree.h"

// 求从根结点到目标结点的路径，结果保存到路径栈path中
bool Path(BiTree& t, BiTree& node, stack<BiTree>& path) {
    if (!t) {
        return false;  // 空树，没有路径
    }
    if (t == node) {
        path.push(t);  // 找到目标结点，将其入栈
        return true;
    }
    if (Path(t->lchild, node, path)) {
        path.push(t);  // 左子树中找到目标结点，将其入栈
        return true;
    }
    if (Path(t->rchild, node, path)) {
        path.push(t);  // 右子树中找到目标结点，将其入栈
        return true;
    }
    return false;  // 没有找到目标结点，路径不存在
}

void TestPath(BiTree& t, ElemType tar) {
    printf("test begin\n");

    BiTree node = SearchNode(t, tar);
    stack<BiTree> path;
    if (Path(t, node, path)) {
        printf("结点%c的路径为：", node->data);
        while (!path.empty()) {
            printf("%c ", path.top()->data);
            path.pop();
        }
        printf("\n");
    } else {
        printf("没有找到结点%c的路径\n", tar);
    }

    printf("test end\n");
}

int main() {
    BiTree root0;
    ElemType arr0[] = {};
    LevelOrderCreateBiTree(root0, arr0, 0);
    TestPath(root0, 'A');

    BiTree root1;
    ElemType arr1[] = {'A'};
    LevelOrderCreateBiTree(root1, arr1, 1);
    TestPath(root1, 'A');
    TestPath(root1, 'B');

    BiTree root2;
    ElemType arr2[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    LevelOrderCreateBiTree(root2, arr2, 7);
    TestPath(root2, 'A');
    TestPath(root2, 'B');
    TestPath(root2, 'G');

    BiTree root3;
    ElemType arr3[] = {'A', 'B', 'C', '#', '#', 'D', 'E', '#',
                       'F', '#', '#', 'G', '#', '#', '#'};
    LevelOrderCreateBiTree(root3, arr3, 15);
    TestPath(root3, 'A');
    TestPath(root3, 'B');
    TestPath(root3, 'F');
    TestPath(root3, 'G');
    TestPath(root3, 'H');

    return 0;
}