#include <iostream>

#include "string.h"

using namespace std;

int main() {
    SqString s, t, r;
    char cstr[] = "hello world";
    StrAssign(s, cstr);
    printf("%s\n", s.data);

    StrCopy(s, t);
    printf("%s\n", t.data);

    printf("%d\n", Strcmp(s, t));

    if (StrConcat(s, t, r)) {
        printf("%s\n", r.data);
    }

    printf("%d\n", Strcmp(s, r));

    return 0;
}