#include "string.h"

int main() {
    LinkString s;
    char cstr0[] = "hello";
    StrAssign(s, cstr0);
    PrintStr(s);

    LinkString t;
    char cstr1[] = "world";
    StrAssign(t, cstr1);
    PrintStr(t);

    LinkString r;
    StrConcat(s, t, r);
    PrintStr(r);

    printf("%s\n", StrEqual(s, t) ? "true" : "false");

    return 0;
}