#pragma once

#include <stdlib.h>

using namespace std;

typedef int ElemType;
typedef struct QNode {
    ElemType data;       // 数据域
    struct QNode* next;  // 指针域
} QNode;

typedef struct LinkQueue {
    QNode* front;  // 队头指针
    QNode* rear;   // 队尾指针
} LinkQueue;

// 初始化队列
// 成功，返回true
// 失败，返回false
bool InitQueue(LinkQueue& q) {
    q.front = q.rear = (QNode*)malloc(sizeof(QNode));
    if (!q.front) {
        return false;
    }
    q.front->next = NULL;
    return true;
}

// 将数据元素e入队
// 成功，返回true
// 失败，返回false
bool EnQueue(LinkQueue& q, ElemType e) {
    QNode* p = (QNode*)malloc(sizeof(QNode));
    if (!p) {
        return false;
    }
    p->data = e;  // 设置新结点
    p->next = NULL;
    q.rear->next = p;
    q.rear = p;  // 尾插法，将新结点插入到队尾
    return true;
}

// 出队，用e返回队头元素
// 成功，返回true
// 失败，返回false
bool DeQueue(LinkQueue& q, ElemType& e) {
    if (q.front == q.rear) {
        return false;  // 队列为空
    }
    QNode* p = q.front->next;
    e = p->data;
    q.front->next = p->next;  // 删除队头结点
    if (q.rear == p) {
        q.rear = q.front;  // 当前队列只有一个结点时防止尾指针丢失
    }
    free(p);
    return true;
}
