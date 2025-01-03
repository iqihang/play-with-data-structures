#include <iostream>

#include "string.h"

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

void GetNext(SqString t, int next[]) {
    next[0] = 0;  // 第一个字符的最大公共前后缀长度为0
    for (int i = 1; i < t.length; ++i) {
        int j = next[i - 1];  // 上一个字符的最大公共前后缀长度
        while (j > 0 && t.data[i] != t.data[j]) {
            j = next[j - 1];  // 不匹配，回溯到上一个可能的匹配位置
        }
        // 匹配成功，最大公共前后缀长度在j的基础上加1
        // 回溯到0，匹配失败，最大公共前后缀长度为0
        next[i] = t.data[i] == t.data[j] ? j + 1 : 0;
    }
}

int KMPMatching(SqString s, SqString t) {
    int next[MAXSIZE];
    GetNext(t, next);
    for (int i = 0, j = 0; i < s.length; ++i) {
        while (j > 0 && s.data[i] != t.data[j]) {
            j = next[j - 1];  // 不匹配，回溯到上一个可能的匹配位置
        }
        if (s.data[i] == t.data[j]) {
            ++j;  // 继续匹配下一个字符
        }
        if (j == t.length) {
            return i - t.length + 1;  // 匹配成功，返回匹配的起始位置
        }
    }
    return -1;
}

void TestPatternMatching(char s1[], char s2[]) {
    printf("test begin\n");

    struct {
        char name[20];
        int (*pm)(SqString, SqString);
    } testFunc[] = {
        {"BF算法", BFMatching},
        {"KMP算法", KMPMatching},
    };

    SqString s, t;
    StrAssign(s, s1);
    printf("%s\n", s.data);
    StrAssign(t, s2);
    printf("%s\n", t.data);

    for (int i = 0; i < sizeof(testFunc) / sizeof(testFunc[0]); ++i) {
        printf("%s: %d\n", testFunc[i].name, testFunc[i].pm(s, t));
    }

    printf("test end\n");
}

int main() {
    char s0[] = "hello world";
    char t0[] = "he";
    TestPatternMatching(s0, t0);

    char s1[] = "hello world";
    char t1[] = "ld";
    TestPatternMatching(s1, t1);

    char s2[] = "hello world";
    char t2[] = "world";
    TestPatternMatching(s2, t2);

    char s3[] = "hello world";
    char t3[] = "world!";
    TestPatternMatching(s3, t3);

    char s4[] = "aaaaa";
    char t4[] = "aaa";
    TestPatternMatching(s4, t4);

    char s5[] = "CAAGAAAUAUAUACCUCACU";
    char t5[] = "AUAUAC";
    TestPatternMatching(s5, t5);

    char s6[] = "ACAATACAAT";
    char t6[] = "ACAAT";
    TestPatternMatching(s6, t6);

    return 0;
}