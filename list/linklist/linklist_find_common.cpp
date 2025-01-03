#include "linklist.h"

void AddToTail(LinkList& a, LinkList b) {
    if (!a) {
        a = b;
        return;
    }
    if (!b) {
        return;
    }
    LinkList p = a;
    while (p->next) {
        p = p->next;
    }
    p->next = b;
}

LinkList FindCommon(LinkList a, LinkList b) {
    if (!a || !b) {
        return NULL;
    }
    LinkList pa = a, pb = b;
    while (pa != pb) {
        pa = pa ? pa->next : b;  // pa遍历a + b，长度对齐
        pb = pb ? pb->next : a;  // pb遍历b + a，长度对齐
    }
    return pa;
}

int main() {
    ElemType a[] = {1, 2, 3};
    ElemType b[] = {1, 2, 3, 4, 5};
    ElemType c[] = {1, 3, 5, 7, 9};
    ElemType d[] = {2, 10};

    LinkList la = CreateList2(a, 3);
    LinkList lb = CreateList2(b, 5);
    LinkList lc = CreateList2(c, 5);
    LinkList ld = CreateList2(d, 2);

    // 测试1
    LinkList r1 = FindCommon(la, lb);
    std::cout << "测试1：" << std::endl;
    PrintList(r1);

    // 测试2
    LinkList r2 = FindCommon(lb, lc);
    std::cout << "测试2：" << std::endl;
    PrintList(r2);

    AddToTail(la, ld);
    AddToTail(lb, ld);
    AddToTail(lc, ld);

    // 测试3
    LinkList r3 = FindCommon(la, lb);
    std::cout << "测试3：" << std::endl;
    PrintList(r3);

    // 测试4
    LinkList r4 = FindCommon(lb, lc);
    std::cout << "测试4：" << std::endl;
    PrintList(r4);

    return 0;
}