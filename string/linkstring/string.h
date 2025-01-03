#pragma once

#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct SNode {
    char c;
    struct SNode* next;
} SNode, *LinkString;

bool StrAssign(LinkString& s, char cstr[]) {
    s = (LinkString)malloc(sizeof(SNode));  // 创建头结点
    if (!s) {
        return false;
    }
    s->next = NULL;
    LinkString tail = s;
    for (int i = 0; cstr[i] != '\0'; ++i) {
        LinkString node = (LinkString)malloc(sizeof(SNode));
        node->c = cstr[i];
        tail->next = node;
        tail = node;  // 尾插法，p始终指向尾结点
    }
    tail->next = NULL;
    return true;
}

bool StrConcat(LinkString s, LinkString t, LinkString& r) {
    r = (LinkString)malloc(sizeof(SNode));  // 创建头结点
    if (!r) {
        return false;
    }
    r->next = NULL;
    LinkString tail = r;
    while (s->next) {
        LinkString node = (LinkString)malloc(sizeof(SNode));
        node->c = s->next->c;
        tail->next = node;
        tail = node;
        s = s->next;
    }
    while (t->next) {
        LinkString node = (LinkString)malloc(sizeof(SNode));
        node->c = t->next->c;
        tail->next = node;
        tail = node;
        t = t->next;
    }
    tail->next = NULL;
    return true;
}

bool StrEqual(LinkString s, LinkString t) {
    while (s->next && t->next) {
        if (s->next->c != t->next->c) {
            return false;
        }
        s = s->next;
        t = t->next;
    }
    return s->next == NULL && t->next == NULL;
}

void PrintStr(LinkString s) {
    while (s->next) {
        printf("%c", s->next->c);
        s = s->next;
    }
    printf("\n");
}