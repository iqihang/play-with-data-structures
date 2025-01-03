#pragma once

#include <iostream>

typedef struct node {
    int data;
    struct node* next;
} NODE;

typedef struct node* LinkList;

// 尾插法创建带头结点的单链表，使用数组a中n个元素初始化结点，返回头指针
LinkList CreateList(int a[], int n) {
    LinkList head = new NODE;  // 创建头结点
    head->next = NULL;         // 链表初始为空表
    LinkList end = head;  // 尾指针指向最后一个结点，用于插入新结点
    for (int i = 0; i < n; ++i) {
        LinkList node = new NODE;  // 创建新链表结点
        node->data = a[i];  // 将数组a中的元素赋值给新结点的数据域
        end->next = node;  // 将新结点插入到尾结点之后
        end = node;        // 更新尾指针指向新结点
    }
    end->next = NULL;  // 尾结点的指针域置空，此句不可省
    return head;
}

// 遍历带头结点的单链表，依次输出每个结点的数据域
void PrintList(LinkList head) {
    if (!head) {
        return;  // head为空，链表不存在
    }
    for (LinkList p = head->next; p; p = p->next) {  // 遍历链表
        printf("%d ", p->data);                      // 输出结点的数据域
    }
    printf("\n");
}