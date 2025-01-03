#include <stdlib.h>

#include "linklist.h"

#define N 100  // data域绝对值的最大值，data域绝对值的范围为[0, N]

void DeleteDuplicate(LinkList head, int n) {
    if (!head) {
        return;  // head为空，链表不存在
    }
    bool* slots = new bool[n + 1];  // 用于记录每个结点data域绝对值是否出现过
    for (int i = 0; i <= n; ++i) {  // 初始化slot数组
        slots[i] = false;
    }
    for (LinkList p = head; p->link;) {
        int key = abs(p->link->data);  // 计算p的后继结点data域绝对值
        if (slots[key]) {  // 如果p的后继结点data域绝对值出现过，删除p的后继结点
            LinkList node = p->link;
            p->link = node->link;
            delete node;
        } else {  // 否则，将p的后继结点data域绝对值标记为出现过
            slots[key] = true;
            p = p->link;
        }
    }
    delete[] slots;
}

void TestDeleteDuplicate(LinkList head) {
    printf("test begin\n");
    PrintList(head);
    DeleteDuplicate(head, N);
    PrintList(head);
    printf("test end\n");
}

int main() {
    LinkList head;

    // 测试0
    int a0[] = {};
    head = CreateList(a0, 0);
    TestDeleteDuplicate(head);

    // 测试1
    int a1[] = {1, 2, 3, 3, -3, -3, -1};
    head = CreateList(a1, 7);
    TestDeleteDuplicate(head);

    // 测试2
    int a2[] = {1, 2, 3, 4, 5, 6, 7};
    head = CreateList(a2, 7);
    TestDeleteDuplicate(head);

    // 测试3
    int a3[] = {1, 1, 1, 1, 1, 1, 1};
    head = CreateList(a3, 7);
    TestDeleteDuplicate(head);

    // 测试4
    int a4[] = {1, 2, 100, 3, -100, 3, -4};
    head = CreateList(a4, 7);
    TestDeleteDuplicate(head);

    // 测试5
    int a5[] = {1, 1, 0, 0, 1, 0, 1};
    head = CreateList(a5, 7);
    TestDeleteDuplicate(head);

    return 0;
}