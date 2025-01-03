#pragma once

#define MAXSIZE 100

typedef struct {
    char data[MAXSIZE + 1];
    int length;
} SqString;

void StrAssign(SqString& s, char cstr[]) {
    int i;
    for (i = 0; cstr[i] != '\0'; ++i) {
        s.data[i] = cstr[i];
    }
    s.length = i;
    s.data[s.length] = '\0';  // 不要忘记字符串结束符'\0'
}