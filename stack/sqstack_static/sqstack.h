#pragma once

#include <stdlib.h>

using namespace std;

#define STACKSIZE 100  //  栈初始数组大小
typedef int ElemType;
typedef struct {
    ElemType data[STACKSIZE];  //   栈数组
    int top;                   //   栈顶指针
} SqStack;

// 初始化栈
void InitStack(SqStack& s) {
    s.top = 0;  // 栈空时栈顶指针为0
}

// 将元素e压入栈s中
// 成功，返回true
// 失败，返回false
bool push(SqStack& s, ElemType e) {
    if (s.top == STACKSIZE) {
        return false;  // 栈满
    }
    s.data[s.top++] = e;  // 元素e压入栈顶，栈顶指针加1
    return true;
}

// 从栈s中弹出栈顶元素，并用e返回
// 成功，返回true
// 失败，返回false
bool pop(SqStack& s, ElemType& e) {
    if (s.top == 0) {
        return false;  // 栈空
    }
    e = s.data[--s.top];  // 栈顶元素出栈，栈顶指针减1
    return true;
}

// 取栈s的栈顶元素，并用e返回
// 成功，返回true
// 失败，返回false
bool GetTop(SqStack& s, ElemType& e) {
    if (s.top == 0) {
        return false;  // 栈空
    }
    e = s.data[s.top - 1];  // 栈顶元素
    return true;
}

// 判断栈s是否为空
// 空，返回true
// 非空，返回false
bool Empty(SqStack& s) {
    return s.top == 0;  // 栈空
}