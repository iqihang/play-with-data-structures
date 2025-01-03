#include "linklist.h"

LinkList MergeList(LinkList a, LinkList b) {
    // head为合并后链表的头结点，tailp为合并后链表的尾结点指针
    LinkList head = NULL, *tailp = &head;
    while (a && b) {
        if (a->data < b->data) {
            *tailp = a;
            a = a->next;
        } else {
            *tailp = b;
            b = b->next;
        }
        tailp = &(*tailp)->next;
    }
    *tailp = a ? a : b;
    return head;
}

LinkList MergeSort(LinkList head) {
    if (!head || !head->next) {
        return head;
    }
    // 快慢指针找中点
    LinkList slow(head);
    for (LinkList fast = head->next; fast && fast->next;
         fast = fast->next->next) {
        slow = slow->next;
    }
    LinkList mid = slow->next;
    slow->next = NULL;
    // 合并将切分后的有序链表
    return MergeList(MergeSort(head), MergeSort(mid));
}

void TestMergeSort(LinkList head) {
    printf("test begin\n");
    PrintList(head);
    head->next = MergeSort(head->next);
    PrintList(head);
    printf("test end\n");
}

int main() {
    LinkList head;

    int a0[] = {};
    head = CreateList(a0, 0);
    TestMergeSort(head);

    int a1[] = {1};
    head = CreateList(a1, 1);
    TestMergeSort(head);

    int a2[] = {1, -2};
    head = CreateList(a2, 2);
    TestMergeSort(head);

    int a3[] = {-2, 1};
    head = CreateList(a3, 2);
    TestMergeSort(head);

    int a4[] = {1, -2, 3};
    head = CreateList(a4, 3);
    TestMergeSort(head);

    int a5[] = {3, 1, 1, 3, -2};
    head = CreateList(a5, 5);
    TestMergeSort(head);

    return 0;
}