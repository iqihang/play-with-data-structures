#include "linklist.h"

int GetLength(LinkList head) {
    int len = 0;
    for (LinkList p = head->next; p; p = p->next) {
        len++;
    }
    return len;
}

void RightRotate(LinkList head, int k) {
    if (!head) {
        return;  // head为空，链表不存在
    }
    int len = GetLength(head);  // 获取链表长度
    k = k % len;                // 计算实际需要旋转的位置
    if (k == 0) {
        return;  // k为0，无需旋转
    }
    // 使用快慢指针法找到倒数第k个结点
    LinkList fast = head;  // fast指向最后一个结点的前驱
    for (int i = 0; i < k; ++i) {
        fast = fast->next;
    }
    LinkList slow = head;  // slow指向倒数第k个结点的前驱
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = head->next;  // 将链表首尾相连
    head->next = slow->next;  // 将倒数第k个结点作为新的链表的首结点
    slow->next = NULL;  // 将倒数第k个结点的前驱与新的链表断开
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