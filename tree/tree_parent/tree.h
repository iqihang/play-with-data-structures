#pragma once

// 树的双亲表示法
#define MAXSIZE 100
typedef int ElemType;
typedef struct PTNode {
    ElemType data;
    int parent;
} PTNode;
typedef struct {
    PTNode nodes[MAXSIZE];
    int root;  //  根结点位置
    int num;   //  结点数
} PTree;