#include "linklist.h"

void ReverseList(LinkList head) {
    if (!head || !head->next) {
        return;  // head为空或者只有一个结点，无需反转
    }
    LinkList p = head->next;
    head->next = NULL;
    while (p) {
        LinkList node = p;  // 记录当前结点
        p = p->next;        // 将p指向下一个结点
        node->next = head->next;
        head->next = node;  // 头插法，将node结点插入到head结点之后
    }
}

int main() {
    LinkList head;

    ElemType a0[] = {1};
    head = CreateList(a0, 1);
    PrintList(head);
    ReverseList(head);
    PrintList(head);

    ElemType a1[] = {1, 2, 3, 4, 5, 6, 7};
    head = CreateList(a1, 7);
    PrintList(head);
    ReverseList(head);
    PrintList(head);

    return 0;
}