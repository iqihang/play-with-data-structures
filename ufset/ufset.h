#pragma once

#include <stdlib.h>
#include <string>

using namespace std;

typedef string ElemType;
typedef struct {
    ElemType data;  // 数据域
    int rank;       // 秩，用于启发式合并
    int parent;     // 父节点的下标
} UFSNode;
typedef struct {
    UFSNode* nodes;
    int size;
} UFSTree;

// 初始化并查集
bool InitUFS(UFSTree& t, ElemType a[], int n) {
    if (n <= 0) {
        return false;
    }
    t.nodes = (UFSNode*)malloc(sizeof(UFSNode) * n);
    if (!t.nodes) {
        return false;
    }
    t.size = n;
    for (int i = 0; i < n; ++i) {
        t.nodes[i].data = a[i];  // 初始化数据域
        t.nodes[i].rank = 0;     // 秩初始为0
        t.nodes[i].parent = i;   // 父节点初始为自身
    }
    return true;
}

// 在并查集中查找下标为i的元素所在集合根节点的下标
int Find(UFSTree& t, int i) {
    if (i < 0 || i >= t.size) {
        return -1;  // 下标越界
    }
    if (t.nodes[i].parent != i) {
        return Find(t, t.nodes[i].parent);
    }
    return i;
}

bool Union(UFSTree& t, int i, int j) {
    i = Find(t, i);  // 查找i所在集合的根节点下标
    j = Find(t, j);  // 查找j所在集合的根节点下标
    if (i == -1 || j == -1) {
        return false;  // 下标越界
    }
    if (i == j) {
        return true;  // 两个元素已经在同一个集合中
    }
    // 将秩小的集合合并到秩大的集合中
    if (t.nodes[i].rank < t.nodes[j].rank) {
        t.nodes[i].parent = j;
    } else if (t.nodes[i].rank > t.nodes[j].rank) {
        t.nodes[j].parent = i;
    } else {                    // 两个集合的秩相等
        t.nodes[j].parent = i;  // 将j所在集合合并到i所在集合中
        ++t.nodes[i].rank;      // i的秩加1
    }
    return true;
}

void PrintUFS(UFSTree& t) {
    for (int i = 0; i < t.size; ++i) {
        printf("%d: %s, set: %d, rank: %d\n", i, t.nodes[i].data.c_str(),
               Find(t, i), t.nodes[i].rank);
    }
    printf("\n");
}