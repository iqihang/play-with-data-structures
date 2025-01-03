#include "linklist.h"

void ReverseList(NODE* head) {
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

void Rearrange(NODE* head) {
    // 快慢指针找链表中点
    NODE* slow = head;
    for (NODE* fast = head; fast && fast->next; fast = fast->next->next) {
        slow = slow->next;  // 快指针走两步，慢指针走一步
    }
    // 采用头插法将链表的后半部分转置
    ReverseList(slow);  // 转置slow->next到链表尾结点之间的链表
    NODE* bottom = slow->next;  // bottom指向链表后半部分
    slow->next = NULL;  // 断开链表前半部分和后半部分的连接
    // 将链表的后半部分交叉插入到前半部分中
    for (NODE *p = head->next, *q = bottom; q;) {
        NODE* node = q;  // 记录当前结点
        q = q->next;     // 将q指向下一个结点
        node->next = p->next;
        p->next = node;  // 交叉插入，将node结点插入到p结点之后
        p = node->next;  // p指向下一个结点
    }
}

int main() {
    NODE* head;

    // 空链表
    int a0[] = {};
    head = CreateList(a0, 0);
    PrintList(head);
    Rearrange(head);
    PrintList(head);

    // 只有一个结点的链表
    int a1[] = {1};
    head = CreateList(a1, 1);
    PrintList(head);
    Rearrange(head);
    PrintList(head);

    // 奇数个结点的链表
    int a2[] = {1, 2, 3, 4, 5};
    head = CreateList(a2, 5);
    PrintList(head);
    Rearrange(head);
    PrintList(head);

    // 偶数个结点的链表
    int a3[] = {1, 2, 3, 4, 5, 6};
    head = CreateList(a3, 6);
    PrintList(head);
    Rearrange(head);
    PrintList(head);

    return 0;
}