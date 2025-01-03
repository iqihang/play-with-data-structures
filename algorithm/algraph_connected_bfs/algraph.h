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

// 创建无向图
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
        ArcNode* arc1 = (ArcNode*)malloc(sizeof(ArcNode));
        if (!arc1) {
            return false;
        }
        arc1->adjvex = edges[i].dest;  // 设置边所指向的顶点的位置
        arc1->info = edges[i].weight;  // 设置边的权值
        arc1->nextarc = g.adjlist[edges[i].src].firstarc;
        g.adjlist[edges[i].src].firstarc = arc1;  // 头插法插入边结点

        ArcNode* arc2 = (ArcNode*)malloc(sizeof(ArcNode));
        if (!arc2) {
            return false;
        }
        arc2->adjvex = edges[i].src;   // 设置边所指向的顶点的位置
        arc2->info = edges[i].weight;  // 设置边的权值
        arc2->nextarc = g.adjlist[edges[i].dest].firstarc;
        g.adjlist[edges[i].dest].firstarc = arc2;  // 头插法插入边结点
    }
    return true;
}

// 以src为源点，广度优先遍历图g，visited为访问标记数组，visit为访问函数
void BFS(ALGraph& g, int src, bool visited[], void (*visit)(VNode)) {
    if (src >= g.n) {
        return;  // 超出范围
    }
    queue<int> q;
    q.push(src);            // 将src入队
    visited[src] = true;    // 标记src已访问
    visit(g.adjlist[src]);  // 访问src
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (ArcNode* arc1 = g.adjlist[v].firstarc; arc1;
             arc1 = arc1->nextarc) {
            if (!visited[arc1->adjvex]) {
                q.push(arc1->adjvex);          // 将未访问的邻接点入队
                visited[arc1->adjvex] = true;  // 标记邻接点已访问
                visit(g.adjlist[arc1->adjvex]);  // 访问邻接点
            }
        }
    }
}