#pragma once

#include <stdlib.h>

using namespace std;

#define STACKSIZE 100      //  栈初始大小
#define STACKINCREMENT 10  //  存储空间分配增量
typedef int ElemType;
typedef struct {
    ElemType* bottom;  // 栈不存在时值为NULL
    ElemType* top;     // 栈顶指针
    int stacksize;     // 当前已分配空间，以元素为单位
} SqStack;

// 初始化栈
// 成功，返回true
// 失败，返回false
bool InitStack(SqStack& s) {
    s.bottom = (ElemType*)malloc(STACKSIZE * sizeof(ElemType));
    if (!s.bottom) {
        return false;
    }
    s.top = s.bottom;         // 栈空时栈顶指针和栈底指针相等
    s.stacksize = STACKSIZE;  // 栈初始大小为STACKSIZE
    return true;
}

// 将元素e压入栈s中
// 成功，返回true
// 失败，返回false
bool push(SqStack& s, ElemType e) {
    if (s.top - s.bottom >= s.stacksize) {  // 栈满，追加存储空间
        s.bottom = (ElemType*)realloc(
            s.bottom, (s.stacksize + STACKINCREMENT) * sizeof(ElemType));
        if (!s.bottom) {
            return false;
        }
        s.top = s.bottom + s.stacksize;  // 更新栈顶指针
        s.stacksize += STACKINCREMENT;   // 更新栈大小
    }
    *s.top++ = e;  // 元素e压入栈顶，栈顶指针加1
    return true;
}

// 从栈s中弹出栈顶元素，并用e返回
// 成功，返回true
// 失败，返回false
bool pop(SqStack& s, ElemType& e) {
    if (s.top == s.bottom) {
        return false;  // 栈空
    }
    e = *--s.top;  // 栈顶元素出栈，栈顶指针减1
    return true;
}

// 取栈s的栈顶元素，并用e返回
// 成功，返回true
// 失败，返回false
bool GetTop(SqStack& s, ElemType& e) {
    if (s.top == s.bottom) {
        return false;  // 栈空
    }
    e = *(s.top - 1);  // 不改变栈顶指针
    return true;
}

// 判断栈s是否为空
// 空，返回true
// 非空，返回false
bool Empty(SqStack& s) {
    return s.top == s.bottom;  // 栈空
}