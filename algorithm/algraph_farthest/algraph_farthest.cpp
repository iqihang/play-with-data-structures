#include "algraph.h"

VNode farthest;
void Record(VNode t) { farthest = t; }

// 求图g中以src为源点的最远距离的结点
void FarthestNode(ALGraph& g, int src) {
    bool visited[MAXSIZE] = {false};  // 初始化访问标记数组
    BFS(g, src, visited, Record);  // 广度优先遍历，记录最远距离的结点
}

void TestFarthestNode(VertexInfo vexs[], int n, Edge edges[], int e, int src) {
    ALGraph g;
    CreateGraph(g, vexs, n, edges, e);
    FarthestNode(g, src);
    printf("%c 的最远距离的结点为：%c\n", g.adjlist[src].info, farthest.info);
}

int main() {
    VertexInfo vexs0[] = {'A', 'B', 'C', 'D', 'E'};
    Edge edges0[] = {{0, 1, 1}, {0, 2, 1}, {1, 3, 1}, {2, 3, 1}, {3, 4, 1}};
    TestFarthestNode(vexs0, sizeof(vexs0) / sizeof(vexs0[0]), edges0,
                     sizeof(edges0) / sizeof(edges0[0]), 1);

    VertexInfo vexs1[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    Edge edges1[] = {{0, 1, 1}, {0, 2, 1}, {1, 3, 1}, {1, 4, 1},
                     {2, 4, 1}, {3, 5, 1}, {4, 5, 1}};
    TestFarthestNode(vexs1, sizeof(vexs1) / sizeof(vexs1[0]), edges1,
                     sizeof(edges1) / sizeof(edges1[0]), 2);

    VertexInfo vexs2[] = {'A', 'B', 'C', 'D', 'E'};
    Edge edges2[] = {{0, 1, 1}, {0, 2, 1}, {1, 3, 1},
                     {2, 3, 1}, {3, 4, 1}, {4, 2, 1}};
    TestFarthestNode(vexs2, sizeof(vexs2) / sizeof(vexs2[0]), edges2,
                     sizeof(edges2) / sizeof(edges2[0]), 0);

    VertexInfo vexs3[] = {'A', 'B', 'C', 'D', 'E'};
    Edge edges3[] = {{0, 1, 1}, {0, 2, 1}, {1, 4, 1}};
    TestFarthestNode(vexs3, sizeof(vexs3) / sizeof(vexs3[0]), edges3,
                     sizeof(edges3) / sizeof(edges3[0]), 1);

    return 0;
}