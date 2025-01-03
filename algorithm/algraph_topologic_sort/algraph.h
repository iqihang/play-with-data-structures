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

void PrintGraph(ALGraph& g) {
    for (int i = 0; i < g.n; ++i) {
        printf("%c: ", g.adjlist[i].info);
        ArcNode* arc = g.adjlist[i].firstarc;
        while (arc) {
            printf("->%c ", g.adjlist[arc->adjvex].info);
            arc = arc->nextarc;
        }
        printf("\n");
    }
}