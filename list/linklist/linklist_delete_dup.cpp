#include "linklist.h"

void DeleteDuplicate(LinkList head) {
    if (!head) {
        return;  // head为空，链表不存在
    }
    for (LinkList p = head->next; p; p = p->next) {
        ElemType e = p->data;  // 记录当前结点的数据域，用于比较
        for (LinkList q = p; q->next;) {
            if (q->next->data == e) {  // 找到重复结点，此时q指向重复结点的前驱
                LinkList node = q->next;
                q->next = node->next;  // 删除重复结点，q保持不变
                delete node;           // 释放重复结点的空间
            } else {
                q = q->next;  // 没有找到重复结点，q向后移动
            }
        }
    }
}

void TestDeleteDuplicate(LinkList head) {
    std::cout << "test begin" << std::endl;
    PrintList(head);
    DeleteDuplicate(head);
    PrintList(head);
    std::cout << "test end" << std::endl;
}

int main() {
    LinkList head;

    // 测试0
    ElemType a0[] = {};
    head = CreateList2(a0, 0);
    TestDeleteDuplicate(head);

    // 测试1
    ElemType a1[] = {1, 2, 3, 3, 3, 3, 3};
    head = CreateList2(a1, 7);
    TestDeleteDuplicate(head);

    // 测试2
    ElemType a2[] = {1, 2, 3, 4, 5, 6, 7};
    head = CreateList2(a2, 7);
    TestDeleteDuplicate(head);

    // 测试3
    ElemType a3[] = {1, 1, 1, 1, 1, 1, 1};
    head = CreateList2(a3, 7);
    TestDeleteDuplicate(head);

    // 测试4
    ElemType a4[] = {1, 2, 3, 3, 3, 3, 4};
    head = CreateList2(a4, 7);
    TestDeleteDuplicate(head);

    // 测试5
    ElemType a5[] = {1, 1, 0, 0, 1, 0, 1};
    head = CreateList2(a5, 7);
    TestDeleteDuplicate(head);

    return 0;
}