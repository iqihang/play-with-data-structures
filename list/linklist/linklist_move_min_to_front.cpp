#include "linklist.h"

void MoveMinToFront(LinkList head) {
    if (!head) {
        return;  // head为空，链表不存在
    }
    LinkList minPrev = head;
    for (LinkList p = head->next; p->next; p = p->next) {
        if (p->next->data < minPrev->next->data) {
            minPrev = p;  // 更新minPrev，指向最小值结点的前一个结点
        }
    }
    LinkList min = minPrev->next;  // 保存最小值结点
    minPrev->next = min->next;     // 断开minPrev和min结点的连接
    min->next = head->next;
    head->next = min;  // 头插法，将min结点插入到head结点之后
}

int main() {
    ElemType a0[] = {1};
    LinkList head = CreateList2(a0, 1);
    PrintList(head);
    MoveMinToFront(head);
    PrintList(head);

    ElemType a1[] = {1, 2, 3, 4, 5, 6, 7};
    head = CreateList2(a1, 7);
    PrintList(head);
    MoveMinToFront(head);
    PrintList(head);

    ElemType a2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    head = CreateList2(a2, 10);
    PrintList(head);
    MoveMinToFront(head);
    PrintList(head);

    ElemType a3[] = {1, 1, 1, 1, 1, 1, 1};
    head = CreateList2(a3, 7);
    PrintList(head);
    MoveMinToFront(head);
    PrintList(head);

    ElemType a4[] = {2, 3, 4, 5, 1, 6, 7, 8, 9, 10};
    head = CreateList2(a4, 10);
    PrintList(head);
    MoveMinToFront(head);
    PrintList(head);

    return 0;
}