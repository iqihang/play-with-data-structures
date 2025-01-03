#include "linklist.h"

bool HasCycle(LinkList h) {
    for (LinkList slow = h, fast = h; fast && fast->next;) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            return true;
        }
    }
    return false;
}

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

void TestHasCycle(LinkList h) {
    printf("test begin\n");
    printf("%s\n", HasCycle(h) ? "true" : "false");
    printf("test end\n");
}

int main() {
    int a0[] = {};
    LinkList head = CreateList(a0, 0);
    TestHasCycle(head);

    int a1[] = {1, 2, 3, 4, 5};
    LinkList head1 = CreateList(a1, 5);
    TestHasCycle(head1);

    int a2[] = {1, 2, 3, 4, 5, 6, 7};
    LinkList head2 = CreateList(a2, 7);
    TestHasCycle(head2);

    int a3[] = {8, 9, 10};
    LinkList head3 = CreateList(a3, 3);
    TestHasCycle(head3);

    AddToTail(head3, head3);
    TestHasCycle(head3);

    AddToTail(head1, head2);
    TestHasCycle(head1);

    AddToTail(head1, head3);
    TestHasCycle(head1);

    return 0;
}