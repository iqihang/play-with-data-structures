#pragma once

// 树的孩子兄弟表示法
typedef int ElemType;
typedef struct CSNode {
    ElemType data;
    struct CSNode *firstchild, *nextsibing;
} CSNode;