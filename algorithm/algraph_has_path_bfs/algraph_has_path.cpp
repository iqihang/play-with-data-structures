#include "algraph.h"

void DoNothing(VNode v) {}

// 以src为源点，dest为终点，判断src和dest之间是否存在路径
bool HasPath(ALGraph& g, int src, int dest) {
    if (src == dest) {
        return true;  // 找到路径
    }
    bool visited[MAXSIZE] = {false};  // 初始化访问标记数组
    BFS(g, src, visited, DoNothing);  // 标记以src为源点的所有目的点
    return visited[dest];             // 判断dest是否已访问
}

int main() {
    VertexInfo vexs[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    Edge edges[] = {{0, 1, 1}, {0, 2, 1}, {1, 3, 1}, {1, 4, 1},
                    {2, 4, 1}, {3, 5, 1}, {4, 5, 1}};
    ALGraph g;
    CreateGraph(g, vexs, sizeof(vexs) / sizeof(vexs[0]), edges,
                sizeof(edges) / sizeof(edges[0]));
    for (int i = 0; i < g.n; ++i) {
        for (int j = 0; j < g.n; ++j) {
            printf("%c到%c是否有路径: %s\n", vexs[i], vexs[j],
                   (HasPath(g, i, j)) ? "是" : "否");
        }
        printf("\n");
    }

    return 0;
}