#include "linklist.h"

LinkList MergeList(LinkList a, LinkList b) {
    if (!a && !b) {
        return NULL;  // 链表a，b都不存在
    }
    if (!a) {
        return b;  // 链表a不存在，合并结果为链表b
    }
    if (!b) {
        return a;  // 链表b不存在，合并结果为链表a
    }
    LinkList p = a;  // p指向合并后的链表的尾结点
    LinkList pa = a->next, pb = b->next;
    while (pa && pb) {
        if (pa->data < pb->data) {
            p->next = pa;
            p = pa;  // 尾插法，将pa结点插入到c结点之后
            pa = pa->next;
        } else if (pa->data > pb->data) {
            p->next = pb;
            p = pb;  // 尾插法，将pb结点插入到c结点之后
            pb = pb->next;
        } else {  // 相等的情况
            p->next = pa;
            p = pa;  // 尾插法，将pa结点插入到c结点之后
            pa = pa->next;
            LinkList node = pb;  // 删除pb结点
            pb = pb->next;
            delete node;  // 释放pb结点的空间
        }
    }
    p->next = pa ? pa : pb;  // 将剩余的结点插入到c结点之后
    delete b;                // 释放链表b的头结点空间
    return a;                // 合并后的链表为a
}

void TestMergeList(LinkList a, LinkList b) {
    std::cout << "test begin" << std::endl;
    PrintList(a);
    PrintList(b);
    LinkList c = MergeList(a, b);
    PrintList(c);
    std::cout << "test end" << std::endl;
}

int main() {
    // 测试区域 开始

    LinkList a, b;

    // 测试0
    ElemType a0[] = {};
    ElemType b0[] = {1, 3, 5, 7, 9};
    a = CreateList2(a0, 0);
    b = CreateList2(b0, 5);
    TestMergeList(a, b);

    // 测试1
    ElemType a1[] = {1, 3, 5, 7, 9};
    ElemType b1[] = {1, 3, 5, 7, 10};
    a = CreateList2(a1, 5);
    b = CreateList2(b1, 5);
    TestMergeList(a, b);

    // 测试2
    ElemType a2[] = {2, 4, 6, 8, 10, 12};
    ElemType b2[] = {1, 3, 5, 7, 9};
    a = CreateList2(a2, 6);
    b = CreateList2(b2, 5);
    TestMergeList(a, b);

    // 测试3
    ElemType a3[] = {1, 3, 5, 7, 9};
    ElemType b3[] = {11, 13, 15, 17, 19, 21};
    a = CreateList2(a3, 5);
    b = CreateList2(b3, 6);
    TestMergeList(a, b);

    // 测试区域 结束

    return 0;
}