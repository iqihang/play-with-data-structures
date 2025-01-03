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

int Strcmp(SqString s, SqString t) {
    int i;
    for (i = 0; i < s.length && i < t.length; ++i) {
        if (s.data[i] != t.data[i]) {
            return s.data[i] - t.data[i] > 0 ? 1 : -1;
        }
    }
    if (s.length != t.length) {
        return s.length - t.length > 0 ? 1 : -1;
    }
    return 0;
}

bool StrConcat(SqString s, SqString t, SqString& r) {
    if (s.length + t.length > MAXSIZE) {
        return false;
    }
    for (int i = 0; i < s.length; ++i) {
        r.data[i] = s.data[i];
    }
    for (int i = 0; i < t.length; ++i) {
        r.data[s.length + i] = t.data[i];
    }
    r.length = s.length + t.length;
    r.data[r.length] = '\0';  // 不要忘记字符串结束符'\0'
    return true;
}

bool SubString(SqString s, int pos, int len, SqString& sub) {
    if (pos < 1 || pos > s.length || len < 0 || len > s.length - pos + 1) {
        return false;
    }
    for (int i = 0; i < len; ++i) {
        sub.data[i] = s.data[pos + i - 1];
    }
    sub.length = len;
    sub.data[sub.length] = '\0';  // 不要忘记字符串结束符'\0'
    return true;
}

void StrCopy(SqString src, SqString& dest) {
    for (int i = 0; i < src.length; ++i) {
        dest.data[i] = src.data[i];
    }
    dest.length = src.length;
    dest.data[dest.length] = '\0';  // 不要忘记字符串结束符'\0'
}

// 返回子串t在主串s中第一次出现的位置，若不存在，则返回-1
int BFMatching(SqString s, SqString t) {
    int i = 0, j = 0;
    while (i < s.length && j < t.length) {
        if (s.data[i] == t.data[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == t.length) {
        return i - t.length;
    }
    return -1;
}