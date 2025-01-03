#include "linklist.h"

void RightRotate(LinkList head, int k) {
    if (!head) {
        return;  // head为空，链表不存在
    }
    int len = 0;
    LinkList tail = head;
    while (tail->next) {  // 计算链表长度，并找到最后一个结点的前驱
        ++len;
        tail = tail->next;
    }
    k = k % len;  // 计算实际需要旋转的位置
    if (k == 0) {
        return;  // k为0，无需旋转
    }
    tail->next = head->next;             // 将链表首尾相连
    for (int i = 0; i < len - k; ++i) {  // 找到原链表倒数第k个结点的前驱
        tail = tail->next;
    }
    head->next = tail->next;  // 将原链表倒数第k个结点作为新链表的首结点
    tail->next = NULL;  // 将倒数第k个结点的前驱与新的链表断开
}

void TestRightRotate(LinkList head, int k) {
    printf("test begin\n");
    printf("k = %d\n", k);
    PrintList(head);
    RightRotate(head, k);
    PrintList(head);
    printf("test end\n");
}

int main() {
    LinkList head;

    // 测试1
    ElemType a0[] = {1};
    head = CreateList(a0, 1);
    TestRightRotate(head, 1);

    // 测试2
    ElemType a1[] = {1, 2};
    head = CreateList(a1, 2);
    TestRightRotate(head, 1);

    // 测试3
    ElemType a2[] = {1, 2, 3, 4, 5};
    head = CreateList(a2, 5);
    TestRightRotate(head, 2);

    // 测试4
    ElemType a3[] = {1, 2, 3, 4, 5};
    head = CreateList(a3, 5);
    TestRightRotate(head, 0);

    // 测试5
    ElemType a4[] = {1, 2, 3, 4, 5};
    head = CreateList(a4, 5);
    TestRightRotate(head, 5);

    // 测试6
    ElemType a5[] = {1, 2, 3, 4, 5};
    head = CreateList(a5, 5);
    TestRightRotate(head, 7);

    // 测试7
    ElemType a6[] = {1, 2, 3, 4, 5};
    head = CreateList(a6, 5);
    TestRightRotate(head, 25);

    return 0;
}