#include "bst.h"

int main() {
    BSTree t = NULL;

    // 测试递归插入操作
    int a[] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
    for (int i = 0; i < 10; i++) {
        InsertBST(t, a[i]);
    }
    PrintBST(t);
    printf("\n");

    // 测试非递归插入操作
    int b[] = {67, 75, 80, 49, 26, 32, 54, 83, 56, 60};
    for (int i = 0; i < 10; i++) {
        InsertBST2(t, b[i]);
    }
    PrintBST(t);
    printf("\n");

    // 测试递归查找操作
    BSTree p = SearchBST(t, 37);
    if (p) {
        printf("找到了%d\n", p->key);
    } else {
        printf("没找到\n");
    }

    // 测试非递归查找操作
    p = SearchBST2(t, 37);
    if (p) {
        printf("找到了%d\n", p->key);
    } else {
        printf("没找到\n");
    }

    // 测试查找最大关键字
    p = SearchBST(t, 99);
    if (p) {
        printf("找到了%d\n", p->key);
    } else {
        printf("没找到\n");
    }

    // 测试查找最小关键字
    p = SearchBST2(t, 26);
    if (p) {
        printf("找到了%d\n", p->key);
    } else {
        printf("没找到\n");
    }

    // 测试查找不存在的关键字
    p = SearchBST(t, 100);
    if (p) {
        printf("找到了%d\n", p->key);
    } else {
        printf("没找到\n");
    }

    return 0;
}