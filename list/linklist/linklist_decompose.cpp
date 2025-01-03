#include "linklist.h"

void DecomposeList(LinkList& ha, LinkList& hb, LinkList& hc) {
    if (!hc) {
        return;  // hc为空，链表不存在
    }
    ha = hc;          // 将hc的头结点赋值给ha
    hb = InitList();  // 初始化hb链表，为之分配头结点
    for (LinkList p = hc->next; p->next;) {
        LinkList node = p->next;
        p->next = node->next;  // 将node结点从hc中删除
        node->next = hb->next;
        hb->next = node;  // 头插法，将node结点插入到hb
        if (p->next) {    // 防止p->next为空，否则会出现段错误
            p = p->next;  // 将p指向下一个结点
        }
    }
    hc = NULL;  // 将原链表hc置为空，防止指针悬挂
}

int main() {
    ElemType arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    LinkList a, b, c = CreateList2(arr, 8);
    PrintList(c);
    DecomposeList(a, b, c);
    PrintList(a);
    PrintList(b);
    PrintList(c);

    return 0;
}