#pragma once

#include <stdlib.h>

using namespace std;

typedef int ElemType;
typedef struct StackNode {
    ElemType data;           // 数据域
    struct StackNode* next;  // 指针域
} StackNode;
typedef struct {
    StackNode* top;  // 栈顶指针
} LinkStack;

// 初始化栈
// 成功，返回true
// 失败，返回false
bool InitStack(LinkStack& s) {
    s.top = (StackNode*)malloc(sizeof(StackNode));
    if (!s.top) {
        return false;
    }
    s.top->next = NULL;  // 栈空时栈顶指针为NULL
    return true;
}

// 将元素e压入栈s中
// 成功，返回true
// 失败，返回false
bool push(LinkStack& s, ElemType e) {
    StackNode* p = (StackNode*)malloc(sizeof(StackNode));
    if (!p) {
        return false;  // 栈节点分配失败
    }
    p->data = e;
    p->next = s.top->next;  // ①
    s.top->next = p;        // ②
    return true;
}

// 从栈s中弹出栈顶元素，并用e返回
// 成功，返回true
// 失败，返回false
bool pop(LinkStack& s, ElemType& e) {
    if (s.top->next == NULL) {
        return false;  // 栈空
    }
    StackNode* p = s.top->next;  // ①
    s.top->next = p->next;       // 修改栈顶指针 ②
    e = p->data;                 // 获取栈顶元素
    free(p);                     // ③
    return true;
}

// 取栈s的栈顶元素，并用e返回
// 成功，返回true
// 失败，返回false
bool GetTop(LinkStack& s, ElemType& e) {
    if (s.top->next == NULL) {
        return false;  // 栈空
    }
    e = s.top->next->data;  // 获取栈顶元素
    return true;
}

// 判断栈s是否为空
// 空，返回true
// 非空，返回false
bool Empty(LinkStack& s) {
    return s.top->next == NULL;  // 栈空
}