#include "linklist.h"

LinkList ReverseList(LinkList head) {
    if (!head || !head->next) {
        return head;  // head为空或者只有一个结点，无需反转
    }
    LinkList new_head = ReverseList(head->next);  // 递归反转head->next子链表
    head->next->next = head;  // 将当前结点插入到新链表的末尾
    head->next = NULL;        // 断开原来的连接
    return new_head;
}

int main() {
    LinkList head;

    ElemType a0[] = {1};
    head = CreateList2(a0, 1);
    PrintList(head);
    head->next = ReverseList(head->next);
    PrintList(head);

    ElemType a1[] = {1, 2, 3, 4, 5, 6, 7};
    head = CreateList2(a1, 7);
    PrintList(head);
    head->next = ReverseList(head->next);
    PrintList(head);

    return 0;
}