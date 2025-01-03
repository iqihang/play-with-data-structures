#include "linklist.h"

bool DeleteMiddleNode(LinkList head, ElemType mink, ElemType maxk) {
    if (mink >= maxk) {
        return false;  // mink，maxk不合法，返回false
    }
    if (!head) {
        return false;  // head为空，链表不存在，返回false
    }
    for (LinkList p = head; p->next && p->next->data < maxk;) {
        if (p->next->data > mink) {  // 值介于mink和maxk之间，删除该结点
            LinkList node = p->next;  // 保存要删除的结点
            p->next = node->next;     // 断开p->next和node的连接
            delete node;              // 释放node
        } else {
            p = p->next;  // p->next->data不在(mink, maxk)之间，p后移
        }
    }
    return true;
}

void TestDeleteMiddleNode(LinkList head, ElemType mink, ElemType maxk) {
    std::cout << "test begin" << std::endl;
    PrintList(head);
    std::cout << "mink = " << mink << ", maxk = " << maxk << std::endl;
    bool res = DeleteMiddleNode(head, mink, maxk);
    std::cout << "res = " << (res ? "true" : "false") << std::endl;
    PrintList(head);
    std::cout << "test end" << std::endl;
}

int main() {
    LinkList head;

    ElemType a0[] = {1};
    head = CreateList2(a0, 1);
    TestDeleteMiddleNode(head, 2, 0);
    TestDeleteMiddleNode(head, 1, 2);
    TestDeleteMiddleNode(head, 0, 2);

    ElemType a1[] = {1, 2, 3, 4, 5, 6, 7};
    head = CreateList2(a1, 7);
    TestDeleteMiddleNode(head, 3, 8);

    return 0;
}