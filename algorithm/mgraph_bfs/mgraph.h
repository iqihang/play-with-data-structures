#pragma once

#include <iostream>
#include <queue>

using namespace std;

#define MAXSIZE 100       // 最大顶点数
#define INF 65535         // 无穷大，用于表示两个顶点之间没有边
typedef char VertexInfo;  // 顶点相关信息，这里表示顶点名称
typedef int ArcInfo;      // 边相关信息，这里表示权值
typedef struct {
    ArcInfo edges[MAXSIZE][MAXSIZE];  // 邻接矩阵
    VertexInfo vexs[MAXSIZE];         // 存放顶点信息
    int n, e;                         // 图的顶点数和边数
} MGraph;

typedef struct {
    int src;         // 边的起点
    int dest;        // 边的终点
    ArcInfo weight;  // 边的权值
} Edge;

void CreateGraph(MGraph& g, VertexInfo vexs[], int n, Edge edges[], int e) {
    g.n = n;
    g.e = e;
    // 初始化邻接矩阵
    for (int i = 0; i < g.n; ++i) {
        for (int j = 0; j < g.n; ++j) {
            g.edges[i][j] = INF;  // 初始化边为无穷大，表示没有边
        }
    }
    // 初始化顶点信息
    for (int i = 0; i < g.n; ++i) {
        g.vexs[i] = vexs[i];
    }
    // 初始化邻接矩阵
    for (int i = 0; i < g.e; ++i) {
        g.edges[edges[i].src][edges[i].dest] = edges[i].weight;
    }
}

void PrintGraph(MGraph& g) {
    for (int i = 0; i < g.n; ++i) {
        for (int j = 0; j < g.n; ++j) {
            if (g.edges[i][j] == INF) {
                printf("∞ ");
            } else {
                printf("%d ", g.edges[i][j]);
            }
        }
        printf("\n");
    }
}

// 以src为源点，广度优先遍历图g，visited为访问标记数组，visit为访问函数
void BFS(MGraph& g, int src, bool visited[], void (*visit)(VertexInfo)) {
    if (src >= g.n) {
        return;  // 超出范围
    }
    queue<int> q;
    q.push(src);          // 将src入队
    visited[src] = true;  // 标记src已访问
    visit(g.vexs[src]);   // 访问src
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g.n; ++i) {
            if (!visited[i] && g.edges[v][i] != INF) {
                q.push(i);          // 将未访问的邻接点入队
                visited[i] = true;  // 标记邻接点已访问
                visit(g.vexs[i]);   // 访问邻接点
            }
        }
    }
}

// 广度优先遍历图g，visit为访问函数
void BFSTraverse(MGraph& g, void (*visit)(VertexInfo)) {
    bool visited[MAXSIZE] = {false};  // 初始化访问标记数组
    for (int i = 0; i < g.n; ++i) {
        if (!visited[i]) {
            BFS(g, i, visited, visit);  // 若未访问，则递归访问该顶点
        }
    }
}