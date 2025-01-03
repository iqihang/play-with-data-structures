#include "linklist.h"

int PrintLastKth(LinkList h, int k) {
    if (!h || k <= 0) {
        return 0;  // 链表为空或k不合法，返回0
    }
    LinkList last = h;
    for (int i = 0; i < k && last; ++i) {
        last = last->next;
    }
    if (!last) {
        return 0;  // 链表长度不足k，返回0
    }
    LinkList lastKth = h;
    while (last) {
        last = last->next;
        lastKth = lastKth->next;  // 同时移动两个指针
    }
    printf("%d\n", lastKth->data);
    return 1;
}

void TestPrintLastKth(LinkList h, int k) {
    printf("test begin\n");
    printf("k = %d\n", k);
    PrintList(h);
    if (!PrintLastKth(h, k)) {
        printf("倒数第%d个元素不存在\n", k);
    }
    printf("test end\n");
}

int main() {
    int a0[] = {};
    LinkList head = CreateList(a0, 0);
    TestPrintLastKth(head, 1);

    int a1[] = {1, 2, 3, 4, 5};
    LinkList head1 = CreateList(a1, 5);
    TestPrintLastKth(head1, 0);
    TestPrintLastKth(head1, 1);
    TestPrintLastKth(head1, 3);
    TestPrintLastKth(head1, 5);
    TestPrintLastKth(head1, 6);

    return 0;
}