#include <iostream>

using namespace std;

bool Dencendant(int l[], int r[], int n, int u, int v) {
    if (v > n) {
        return false;  // v超出范围
    }
    if (v == 0) {
        return false;  // v为空，没有子孙
    }
    if (l[v] == 0 && r[v] == 0) {
        return false;  // v是叶子结点，没有子孙
    }
    if (l[v] == u || r[v] == u) {
        return true;  // v的左孩子或右孩子是u，u是v的子孙
    }
    return Dencendant(l, r, n, u, l[v]) ||
           Dencendant(l, r, n, u, r[v]);  // 递归搜索v的左子树和右子树
}

void TestDencendant(int l[], int r[], int n, int u, int v) {
    printf("test begin\n");

    if (Dencendant(l, r, n, u, v)) {
        printf("%d 是 %d 的子孙\n", u, v);
    } else {
        printf("%d 不是 %d 的子孙\n", u, v);
    }

    printf("test end\n");
}

int main() {
    // 数组位置0用不上

    // 测试1 只有一个结点
    int l0[] = {0, 0};
    int r0[] = {0, 0};
    TestDencendant(l0, r0, 1, 1, 1);

    // 测试2 只有两个结点
    int l1[] = {0, 2, 0};
    int r1[] = {0, 0, 0};
    TestDencendant(l1, r1, 2, 2, 1);
    TestDencendant(l1, r1, 2, 1, 2);

    // 测试3 只有三个结点，单枝树
    int l2[] = {0, 2, 0, 0};
    int r2[] = {0, 0, 3, 0};
    TestDencendant(l2, r2, 3, 2, 1);
    TestDencendant(l2, r2, 3, 3, 1);
    TestDencendant(l2, r2, 3, 3, 2);

    // 测试4 只有三个结点，双枝树
    int l3[] = {0, 2, 0, 0};
    int r3[] = {0, 3, 0, 0};
    TestDencendant(l3, r3, 3, 2, 1);
    TestDencendant(l3, r3, 3, 3, 1);
    TestDencendant(l3, r3, 3, 3, 2);

    return 0;
}