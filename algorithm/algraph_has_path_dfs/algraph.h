#pragma once

#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;

#define MAXSIZE 100   // 最大顶点数
typedef int ArcInfo;  // 边相关信息，这里表示权值
typedef struct ArcNode {
    int adjvex;               // 该边所指向的顶点的位置
    struct ArcNode* nextarc;  // 指向下一条边的指针
    ArcInfo info;             // 边相关信息，这里表示权值
} ArcNode;                    // 表结点（边结点）定义
typedef char VertexInfo;      // 顶点相关信息，这里表示顶点名称
typedef struct VNode {
    VertexInfo info;    // 顶点相关信息，这里表示顶点名称
    ArcNode* firstarc;  // 指向第一条依附该顶点的边的指针
} VNode;                // 表头结点（顶点结点）定义
typedef struct {
    VNode adjlist[MAXSIZE];  // 邻接表的表头结点数组
    int n, e;                // 图中的顶点数n和边数e
} ALGraph;                   // 图的邻接表定义

typedef struct {
    int src;         // 边的起点
    int dest;        // 边的终点
    ArcInfo weight;  // 边的权值
} Edge;

bool CreateGraph(ALGraph& g, VertexInfo vexs[], int n, Edge edges[], int e) {
    g.n = n;
    g.e = e;
    // 初始化表头结点数组
    for (int i = 0; i < n; ++i) {
        g.adjlist[i].info = vexs[i];
        g.adjlist[i].firstarc = NULL;
    }
    // 初始化边结点数组
    for (int i = 0; i < e; ++i) {
        ArcNode* arc = (ArcNode*)malloc(sizeof(ArcNode));
        if (!arc) {
            return false;
        }
        arc->adjvex = edges[i].dest;  // 设置边所指向的顶点的位置
        arc->info = edges[i].weight;  // 设置边的权值
        arc->nextarc = g.adjlist[edges[i].src].firstarc;
        g.adjlist[edges[i].src].firstarc = arc;  // 头插法插入边结点
    }
    return true;
}

// 以src为源点，深度优先遍历图g，visited为访问标记数组，visit为访问函数
void DFS(ALGraph& g, int src, bool visited[], void (*visit)(VNode)) {
    if (src >= g.n) {
        return;  // 超出范围
    }
    visited[src] = true;    // 标记src已访问
    visit(g.adjlist[src]);  // 访问src
    for (ArcNode* arc = g.adjlist[src].firstarc; arc; arc = arc->nextarc) {
        if (!visited[arc->adjvex]) {
            DFS(g, arc->adjvex, visited, visit);  // 遍历未访问的邻接点
        }
    }
}