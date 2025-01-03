#pragma once

#include <stdlib.h>

using namespace std;

#define MAXSIZE 100

typedef int KeyType;
typedef int ValueType;

typedef struct {
    KeyType key;    // 关键字
    ValueType val;  // 值
} ElemType;

typedef struct HNode {
    ElemType data;  // 数据元素
    struct HNode* next;
} HNode;

typedef struct HashTable {
    HNode* slots[MAXSIZE];                    // 哈希表的数组
    int (*hash)(struct HashTable&, KeyType);  // 哈希函数
    int size;                                 // 哈希表的大小
} HashTable;

bool InitHashTable(HashTable& ht, int n,
                   int (*hash)(struct HashTable&, KeyType)) {
    ht.hash = hash;  // 设置哈希函数
    ht.size = n;     // 设置哈希表的大小
    for (int i = 0; i < n; ++i) {
        ht.slots[i] = (HNode*)malloc(sizeof(HNode));  // 为每个哈希槽分配链表头
        if (!ht.slots[i]) {
            return false;
        }
        ht.slots[i]->next = NULL;
    }
    return true;
}

bool InsertHashTable(HashTable& ht, ElemType e) {
    int idx = ht.hash(ht, e.key);  // 计算哈希值
    for (HNode* p = ht.slots[idx]; p->next; p = p->next) {
        if (p->next->data.key == e.key) {
            return false;  // 元素已存在，插入失败
        }
    }
    HNode* node = (HNode*)malloc(sizeof(HNode));
    if (!node) {
        return false;
    }
    node->data = e;
    node->next = ht.slots[idx]->next;
    ht.slots[idx]->next = node;  // 头插法插入元素
    return true;
}

bool SearchHashTable(HashTable& ht, KeyType key, ValueType& val) {
    int idx = ht.hash(ht, key);  // 计算哈希值
    for (HNode* p = ht.slots[idx]; p->next; p = p->next) {
        if (p->next->data.key == key) {
            val = p->next->data.val;  // 找到元素，返回值
            return true;
        }
    }
    return false;
}

bool DeleteHashTable(HashTable& ht, KeyType key) {
    int idx = ht.hash(ht, key);  // 计算哈希值
    for (HNode* p = ht.slots[idx]; p->next; p = p->next) {
        if (p->next->data.key == key) {
            HNode* node = p->next;
            p->next = node->next;
            free(node);  // 释放内存
            return true;
        }
    }
    return false;
}