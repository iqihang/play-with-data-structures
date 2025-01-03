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
    char a[] = "load";
    char b[] = "be";
    char c[] = "hello";
    char d[] = "ing";

    LinkList la = CreateList(a);
    LinkList lb = CreateList(b);
    LinkList lc = CreateList(c);
    LinkList ld = CreateList(d);

    // 测试1
    LinkList r1 = FindCommon(la, lb);
    std::cout << "测试1：" << std::endl;
    PrintList(la);
    PrintList(lb);
    PrintList(r1);

    // 测试2
    LinkList r2 = FindCommon(lb, lc);
    std::cout << "测试2：" << std::endl;
    PrintList(lb);
    PrintList(lc);
    PrintList(r2);

    AddToTail(la, ld);
    AddToTail(lb, ld);

    // 测试3
    LinkList r3 = FindCommon(la, lb);
    std::cout << "测试3：" << std::endl;
    PrintList(la);
    PrintList(lb);
    PrintList(r3);

    // 测试4
    LinkList r4 = FindCommon(lb, lc);
    std::cout << "测试4：" << std::endl;
    PrintList(lb);
    PrintList(lc);
    PrintList(r4);

    return 0;
}