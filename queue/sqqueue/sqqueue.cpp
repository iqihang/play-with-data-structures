#include <iostream>

#include "sqqueue.h"

int main() {
    SqQueue q;
    ElemType e;

    InitQueue(q);
    if (DeQueue(q, e)) {
        printf("%d\n", e);
    } else {
        printf("队列为空，出队失败\n");
    }
    EnQueue(q, 1);
    EnQueue(q, 2);
    EnQueue(q, 3);
    if (DeQueue(q, e)) {
        printf("%d\n", e);
    } else {
        printf("队列为空，出队失败\n");
    }
    if (DeQueue(q, e)) {
        printf("%d\n", e);
    } else {
        printf("队列为空，出队失败\n");
    }
    EnQueue(q, 4);
    EnQueue(q, 5);
    EnQueue(q, 6);
    if (DeQueue(q, e)) {
        printf("%d\n", e);
    } else {
        printf("队列为空，出队失败\n");
    }
    if (DeQueue(q, e)) {
        printf("%d\n", e);
    } else {
        printf("队列为空，出队失败\n");
    }

    // 没测试边界

    return 0;
}