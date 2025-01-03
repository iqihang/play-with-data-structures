#include <iostream>

#include "sqstack.h"

int main() {
    SqStack s;

    InitStack(s);

    ElemType e;
    if (!GetTop(s, e)) {
        cout << "GetTop failed!" << endl;
    } else {
        cout << "GetTop " << e << endl;
    }

    push(s, 1);
    cout << "push 1" << endl;
    push(s, 2);
    cout << "push 2" << endl;
    push(s, 3);
    cout << "push 3" << endl;
    push(s, 4);
    cout << "push 4" << endl;

    pop(s, e);
    cout << "pop " << e << endl;
    pop(s, e);
    cout << "pop " << e << endl;

    push(s, 5);
    cout << "push 5" << endl;
    push(s, 6);
    cout << "push 6" << endl;

    if (!GetTop(s, e)) {
        cout << "GetTop failed!" << endl;
    } else {
        cout << "GetTop " << e << endl;
    }

    return 0;
}