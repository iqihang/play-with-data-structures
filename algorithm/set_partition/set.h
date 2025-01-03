#pragma once

#define MAXSIZE 100
typedef struct Set {
    int data[MAXSIZE];  // 存储集合元素的数组
    int size;           // 集合元素个数
} Set;

void InitSet(Set& s) { s.size = 0; }

void CreateSet(Set& s, int a[], int n) {
    for (int i = 0; i < n; ++i) {
        s.data[s.size++] = a[i];
    }
}

void PrintSet(Set& s) {
    for (int i = 0; i < s.size; ++i) {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}