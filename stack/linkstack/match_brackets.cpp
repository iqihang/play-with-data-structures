#include <iostream>

#include "linkstack.h"

bool MatchBrackets(char* exp) {
    if (exp == NULL) {
        return false;
    }
    LinkStack s;
    InitStack(s);
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '[') {
            push(s, exp[i]);  // 左括号入栈
        } else if (exp[i] == ')') {
            ElemType x;
            pop(s, x);  // 遇到右括号，弹出栈顶元素
            if (x != '(') {
                return false;
            }
        } else if (exp[i] == ']') {
            ElemType x;
            pop(s, x);  // 遇到右括号，弹出栈顶元素
            if (x != '[') {
                return false;
            }
        } else {
            ;  // 忽略其他字符
        }
    }
    return Empty(s);  // 栈为空，匹配成功
}

int main() {
    char exp0[] = "((a+b)*[c-d])";
    cout << exp0 << endl;
    if (MatchBrackets(exp0)) {
        cout << "匹配成功" << endl;
    } else {
        cout << "匹配失败" << endl;
    }

    char exp1[] = "((a+b)*[c-d]";
    cout << exp1 << endl;
    if (MatchBrackets(exp1)) {
        cout << "匹配成功" << endl;
    } else {
        cout << "匹配失败" << endl;
    }

    char exp2[] = "((a+b)*[c-d])]";
    cout << exp2 << endl;
    if (MatchBrackets(exp2)) {
        cout << "匹配成功" << endl;
    } else {
        cout << "匹配失败" << endl;
    }

    char exp3[] = "((a+b)*[c-d))";
    cout << exp3 << endl;
    if (MatchBrackets(exp3)) {
        cout << "匹配成功" << endl;
    } else {
        cout << "匹配失败" << endl;
    }

    return 0;
}