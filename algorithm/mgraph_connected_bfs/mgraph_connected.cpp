#include "mgraph.h"

int cnt = 0;
void NodeCnt(VertexInfo t) { ++cnt; }

// 判断图g是否连通
bool Connected(MGraph& g) {
    bool visited[MAXSIZE] = {false};  // 初始化访问标记数组
    BFS(g, 0, visited, NodeCnt);      // 深度优先遍历，统计结点数
    return cnt == g.n;
}

void TestConnected(VertexInfo vexs[], int n, Edge edges[], int e) {
    MGraph g;
    CreateGraph(g, vexs, n, edges, e);
    cnt = 0;
    printf("图是否连通：%s\n", Connected(g) ? "是" : "否");
}

int main() {
    VertexInfo vexs0[] = {'A', 'B', 'C', 'D', 'E'};
    Edge edges0[] = {{0, 1, 1}, {0, 2, 1}, {1, 3, 1}, {2, 3, 1}, {3, 4, 1}};
    TestConnected(vexs0, sizeof(vexs0) / sizeof(vexs0[0]), edges0,
                  sizeof(edges0) / sizeof(edges0[0]));

    VertexInfo vexs1[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    Edge edges1[] = {{0, 1, 1}, {0, 2, 1}, {1, 3, 1}, {1, 4, 1},
                     {2, 4, 1}, {3, 5, 1}, {4, 5, 1}};
    TestConnected(vexs1, sizeof(vexs1) / sizeof(vexs1[0]), edges1,
                  sizeof(edges1) / sizeof(edges1[0]));

    VertexInfo vexs2[] = {'A', 'B', 'C', 'D', 'E'};
    Edge edges2[] = {{0, 1, 1}, {0, 2, 1}, {1, 3, 1},
                     {2, 3, 1}, {3, 4, 1}, {4, 2, 1}};
    TestConnected(vexs2, sizeof(vexs2) / sizeof(vexs2[0]), edges2,
                  sizeof(edges2) / sizeof(edges2[0]));

    VertexInfo vexs3[] = {'A', 'B', 'C', 'D', 'E'};
    Edge edges3[] = {{0, 1, 1}, {0, 2, 1}, {1, 4, 1}};
    TestConnected(vexs3, sizeof(vexs3) / sizeof(vexs3[0]), edges3,
                  sizeof(edges3) / sizeof(edges3[0]));

    return 0;
}