#include <functional>

#include "linklist.h"

void MoveExtremToFront(LinkList head,
                       std::function<bool(ElemType, ElemType)> cmp) {
    if (!head) {
        return;  // head为空，链表不存在
    }
    LinkList extremPrev = head;
    for (LinkList p = head->next; p->next; p = p->next) {
        if (cmp(p->next->data, extremPrev->next->data)) {
            extremPrev = p;  // 更新extremPrev，指向极值结点的前一个结点
        }
    }
    LinkList extrem = extremPrev->next;  // 保存极值结点
    extremPrev->next = extrem->next;  // 断开extremPrev和extrem结点的连接
    extrem->next = head->next;
    head->next = extrem;  // 头插法，将extrem结点插入到head结点之后
}

int main() {
    ElemType a1[] = {2, 3, 4, 1, 5, 7, 6};
    LinkList head = CreateList2(a1, 7);
    PrintList(head);
    MoveExtremToFront(head, std::less<ElemType>());
    PrintList(head);
    MoveExtremToFront(head, std::greater<ElemType>());
    PrintList(head);

    return 0;
}