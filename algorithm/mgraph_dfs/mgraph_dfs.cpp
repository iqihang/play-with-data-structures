#include "mgraph.h"

void PrintNode(VertexInfo v) { printf("%c ", v); }

void Test(VertexInfo vexs[], int n, Edge edges[], int e) {
    MGraph g;
    CreateGraph(g, vexs, n, edges, e);
    PrintGraph(g);

    printf("深度优先遍历：");
    DFSTraverse(g, PrintNode);
    printf("\n");
}

int main() {
    VertexInfo vexs0[] = {'A', 'B', 'C', 'D', 'E'};
    Edge edges0[] = {{0, 1, 1}, {0, 2, 1}, {1, 3, 1}, {2, 3, 1}, {3, 4, 1}};
    Test(vexs0, sizeof(vexs0) / sizeof(vexs0[0]), edges0,
         sizeof(edges0) / sizeof(edges0[0]));

    VertexInfo vexs1[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    Edge edges1[] = {{0, 1, 1}, {0, 2, 1}, {1, 3, 1}, {1, 4, 1},
                     {2, 4, 1}, {3, 5, 1}, {4, 5, 1}};
    Test(vexs1, sizeof(vexs1) / sizeof(vexs1[0]), edges1,
         sizeof(edges1) / sizeof(edges1[0]));

    VertexInfo vexs2[] = {'A', 'B', 'C', 'D', 'E'};
    Edge edges2[] = {{0, 1, 1}, {0, 2, 1}, {1, 3, 1},
                     {2, 3, 1}, {3, 4, 1}, {4, 2, 1}};
    Test(vexs2, sizeof(vexs2) / sizeof(vexs2[0]), edges2,
         sizeof(edges2) / sizeof(edges2[0]));

    return 0;
}