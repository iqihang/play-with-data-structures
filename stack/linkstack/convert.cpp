#include <iostream>

#include "linkstack.h"

// 将十进制数n转换为d(二或八)进制数，并输出
void Convert(int n, int d) {
    if (n == 0) {  // 0的d进制数为0，特殊处理
        printf("0\n");
        return;
    }
    bool flag = false;  // flag为true表示n为负数，需要输出负号
    if (n < 0) {
        flag = true;
        n = -n;
    }
    LinkStack s;
    InitStack(s);
    while (n != 0) {
        push(s, n % d);  // 取余，余数入栈
        n /= d;          // 商作为新的被除数
    }
    if (flag) {
        printf("-");  // n为负数，输出负号
    }
    while (!Empty(s)) {  // 栈不为空，输出栈中元素
        ElemType e;
        pop(s, e);        // 弹出栈顶元素
        printf("%d", e);  // 输出栈顶元素
    }
    printf("\n");
}

int main() {
    int arr[] = {0, -1, 666, 123, -123};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d:\n", arr[i]);
        Convert(arr[i], 2);
        Convert(arr[i], 8);
    }
    return 0;
}