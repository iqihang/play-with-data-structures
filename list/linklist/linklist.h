#pragma once

#include <iostream>

typedef int ElemType;    // 数据类型的别名
typedef struct LNode {   // 定义单链表结点类型
    ElemType data;       // 数据域，存放数据元素
    struct LNode* next;  // 指针域，指向后继结点
} LNode, *LinkList;      // 定义单链表结点类型和单链表类型

// 头插法创建带头结点的单链表，使用数组a中n个元素初始化结点，返回头指针
LinkList CreateList(ElemType a[], int n) {
    LinkList head = new LNode;  // 创建头结点
    head->next = NULL;          // 链表初始为空表
    for (int i = 0; i < n; ++i) {
        LinkList node = new LNode;  // 创建新链表结点
        node->data = a[i];  // 将数组a中的元素赋值给新结点的数据域
        node->next = head->next;  // 将新结点插入到头结点之后
        head->next = node;        // 更新头结点的指针域
    }
    return head;
}

// 尾插法创建带头结点的单链表，使用数组a中n个元素初始化结点，返回头指针
LinkList CreateList2(ElemType a[], int n) {
    LinkList head = new LNode;  // 创建头结点
    head->next = NULL;          // 链表初始为空表
    LinkList end = head;  // 尾指针指向最后一个结点，用于插入新结点
    for (int i = 0; i < n; ++i) {
        LinkList node = new LNode;  // 创建新链表结点
        node->data = a[i];  // 将数组a中的元素赋值给新结点的数据域
        end->next = node;  // 将新结点插入到尾结点之后
        end = node;        // 更新尾指针指向新结点
    }
    end->next = NULL;  // 尾结点的指针域置空，此句不可省
    return head;
}

// 带头结点的单链表初始化，返回头指针
LinkList InitList() {
    LinkList head = new LNode;  // 创建头结点
    head->next = NULL;          // 链表初始为空表
    return head;
}

// 按序号查找，在带头结点的单链表中找到第i个结点，并用e返回其数据域的值
// 查找成功，返回true
// 查找失败，返回false
bool GetElem(LinkList head, int i, ElemType& e) {
    if (i <= 0) {
        return false;  // 序号不合法，查找失败
    }
    LinkList p = head;  // 指针p指向头结点，即第0个结点
    for (int j = 0; p && j < i; ++j) {  // 遍历链表，p指向第j个结点
        p = p->next;
    }
    if (!p) {
        return false;  // 指针p为空，第i个结点不存在，查找失败
    }
    e = p->data;  // 用e返回第i个结点的数据域
    return true;
}

// 按值查找，在带头结点的单链表中找到第一个数据域等于e的结点，返回其指针
LinkList LocateElem(LinkList head, ElemType e) {
    if (!head) {
        return NULL;  // head为空，链表不存在
    }
    LinkList p = head->next;     // 指针p指向第一个结点
    while (p && p->data != e) {  // 遍历链表，查找数据域等于e的结点
        p = p->next;
    }
    return p;  // 返回找到的结点指针，若未找到则返回NULL
}

// 在带头结点的单链表中的第i个位置上插入数据域为e的新结点
bool ListInsert(LinkList head, int i, ElemType e) {
    if (i <= 0) {
        return false;  // 序号不合法，插入失败
    }
    LinkList p = head;  // 指针p指向头结点，即第0个结点
    for (int j = 0; p && j < i - 1; ++j) {  // 遍历链表，p指向第j个结点 ①
        p = p->next;                        // ②
    }
    if (!p) {
        return false;  // 指针p为空，第i-1个结点不存在，插入失败
    }
    LinkList node = new LNode;  // 创建新结点 ③
    node->data = e;             // 新结点的数据域赋值为e ④
    node->next = p->next;       // 新结点插入到第i个位置上 ⑤
    p->next = node;             // 更新第i-1个结点的指针域 ⑥
    return true;
}

// 按序号查找，在带头结点的单链表中删除第i个结点，并用e返回其数据域的值
// 删除成功，返回true
// 删除失败，返回false
bool ListDelete(LinkList head, int i, ElemType& e) {
    if (i <= 0) {
        return false;  // 序号不合法，删除失败
    }
    LinkList p = head;  // 指针p指向头结点，即第0个结点
    for (int j = 0; p && j < i - 1; ++j) {  // 遍历链表，p指向第j个结点 ①
        p = p->next;                        // ②
    }
    if (!p || !p->next) {
        return false;  // 指针p为空或p->next为空，第i-1个结点不存在或第i个结点不存在，删除失败
    }
    LinkList node = p->next;  // 指针node指向第i个结点 ③
    p->next = node->next;     // 删除第i个结点 ④
    e = node->data;           // 用e返回第i个结点的数据域 ⑤
    delete node;              // 释放第i个结点的内存空间 ⑥
    return true;
}

// 按值查找，在带头结点的单链表中删除第一个数据域等于e的结点，返回其指针
// 删除成功，返回true
// 删除失败，返回false
bool ListLocalDelete(LinkList head, ElemType e) {
    if (!head) {
        return false;  // head为空，链表不存在
    }
    LinkList p = head;  // 指针p指向头结点，即第0个结点
    while (p->next && p->next->data != e) {  // 遍历链表，查找数据域等于e的结点
        p = p->next;
    }
    if (!p->next) {
        return false;  // 指针p->next为空，未找到数据域等于e的结点，删除失败
    }
    LinkList node = p->next;  // 指针node指向数据域等于e的结点
    p->next = node->next;     // 删除结点
    delete node;              // 释放结点的内存空间
    return true;
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