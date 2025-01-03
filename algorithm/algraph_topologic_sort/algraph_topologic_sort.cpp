#include "algraph.h"

void PrintNode(VNode node) { printf("%c ", node.info); }

// 统计各顶点的入度
void CountInDegree(ALGraph& g, int indegree[]) {
    // 初始化入度数组
    for (int i = 0; i < g.n; ++i) {
        indegree[i] = 0;
    }
    for (int i = 0; i < g.n; ++i) {
        for (ArcNode* p = g.adjlist[i].firstarc; p; p = p->nextarc) {
            ++indegree[p->adjvex];
        }
    }
}

// 拓扑排序
// 若图G无回路，返回true，并通过topo返回G的一个拓扑序列
// 否则，返回false
bool TopologicalSort(ALGraph& g, VNode topo[]) {
    int indegree[MAXSIZE];
    CountInDegree(g, indegree);
    queue<int> q;
    for (int i = 0; i < g.n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);  // 将入度为0的顶点入队
        }
    }
    int cnt = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        topo[cnt++] = g.adjlist[v];
        for (ArcNode* p = g.adjlist[v].firstarc; p; p = p->nextarc) {
            if (--indegree[p->adjvex] == 0) {  // 将v的邻接点的入度减1
                q.push(p->adjvex);             // 将入度为0的顶点入队
            }
        }
    }
    return cnt == g.n;
}

void TestTopologicalSort(VertexInfo vexs[], int n, Edge edges[], int e) {
    ALGraph g;
    CreateGraph(g, vexs, n, edges, e);
    PrintGraph(g);
    VNode topo[MAXSIZE] = {0};
    if (TopologicalSort(g, topo)) {
        printf("拓扑排序结果：");
        for (int i = 0; i < g.n; ++i) {
            PrintNode(topo[i]);
        }
        printf("\n");
    } else {
        printf("图中存在环，无法进行拓扑排序\n");
    }
}

int main() {
    VertexInfo vexs0[] = {'A', 'B', 'C', 'D', 'E'};
    Edge edges0[] = {{0, 1, 1}, {0, 2, 1}, {1, 3, 1}, {2, 3, 1}, {3, 4, 1}};
    TestTopologicalSort(vexs0, sizeof(vexs0) / sizeof(vexs0[0]), edges0,
                        sizeof(edges0) / sizeof(edges0[0]));

    VertexInfo vexs1[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    Edge edges1[] = {{0, 1, 1}, {0, 2, 1}, {1, 3, 1}, {1, 4, 1},
                     {2, 4, 1}, {3, 5, 1}, {4, 5, 1}};
    TestTopologicalSort(vexs1, sizeof(vexs1) / sizeof(vexs1[0]), edges1,
                        sizeof(edges1) / sizeof(edges1[0]));

    VertexInfo vexs2[] = {'A', 'B', 'C', 'D', 'E'};
    Edge edges2[] = {{0, 1, 1}, {0, 2, 1}, {1, 3, 1},
                     {2, 3, 1}, {3, 4, 1}, {4, 2, 1}};
    TestTopologicalSort(vexs2, sizeof(vexs2) / sizeof(vexs2[0]), edges2,
                        sizeof(edges2) / sizeof(edges2[0]));

    return 0;
}