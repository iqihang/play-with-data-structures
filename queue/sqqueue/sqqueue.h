#pragma once

#define QUEQUESIZE 100
typedef int ElemType;
typedef struct queue {
    ElemType data[QUEQUESIZE];
    int front;  // 指向队头元素
    int rear;   // 指向队尾元素的下一个位置
} SqQueue;

void InitQueue(SqQueue& q) {
    q.front = 0;
    q.rear = 0;
}

// 将数据元素e入队
// 成功，返回true
// 失败，返回false
bool EnQueue(SqQueue& q, ElemType e) {
    if ((q.rear + 1) % QUEQUESIZE == q.front) {
        return false;  // 队列满
    }
    q.data[q.rear] = e;                  // 元素e入队
    q.rear = (q.rear + 1) % QUEQUESIZE;  // 队尾指针循环加1
    return true;
}

// 出队，用e返回队头元素
// 成功，返回true
// 失败，返回false
bool DeQueue(SqQueue& q, ElemType& e) {
    if (q.front == q.rear) {
        return false;  // 队列为空
    }
    e = q.data[q.front];                   // 队头元素出队
    q.front = (q.front + 1) % QUEQUESIZE;  // 队头指针循环加1
    return true;
}