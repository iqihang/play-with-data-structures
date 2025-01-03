#include <iostream>

using namespace std;

#define MAXSIZE 100
typedef int AdjMatrix[MAXSIZE][MAXSIZE];
void Change(AdjMatrix& A, AdjMatrix& C, int n);

// 已知邻接矩阵A，求A的传递闭包C
void Change(AdjMatrix& A, AdjMatrix& C, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j];  // 将C初始化为邻接矩阵A
        }
    }
    for (int k = 0; k < n; ++k) {  // 遍历中间点k
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // 如果结点i可以间接通过结点k到达结点j，则将C[i][j]置为1
                if (C[i][k] && C[k][j]) {
                    C[i][j] = 1;
                }
            }
        }
    }
}

void PrintAdjMatrix(AdjMatrix& A, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void TestChange(AdjMatrix& A, AdjMatrix& C, int n) {
    printf("test begin\n");

    PrintAdjMatrix(A, n);
    printf("->\n");
    Change(A, C, n);
    PrintAdjMatrix(C, n);

    printf("test end\n");
}

int main() {
    AdjMatrix A0 = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
    AdjMatrix C0;
    TestChange(A0, C0, 3);

    AdjMatrix A1 = {{0, 1, 0, 1}, {0, 0, 1, 0}, {0, 0, 0, 1}, {0, 0, 0, 0}};
    AdjMatrix C1;
    TestChange(A1, C1, 4);

    return 0;
}