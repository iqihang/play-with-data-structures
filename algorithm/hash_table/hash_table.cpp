#include <iostream>

#include "hash_table.h"

int ModDivision(HashTable& ht, KeyType key) { return key % ht.size; }

void TestInsert(HashTable& ht, ElemType e) {
    if (InsertHashTable(ht, e)) {
        printf("插入 key = %d 成功：val = %d\n", e.key, e.val);
    } else {
        printf("插入 key = %d 失败\n", e.key);
    }
}

void TestSearch(HashTable& ht, KeyType key) {
    ValueType val;
    if (SearchHashTable(ht, key, val)) {
        printf("查找 key = %d 成功：val = %d\n", key, val);
    } else {
        printf("查找 key = %d 失败\n", key);
    }
}

void TestDelete(HashTable& ht, KeyType key) {
    if (DeleteHashTable(ht, key)) {
        printf("删除 key = %d 成功\n", key);
    } else {
        printf("删除 key = %d 失败\n", key);
    }
}

int main() {
    HashTable ht;
    InitHashTable(ht, 10, ModDivision);

    ElemType e1 = {1, 1};
    TestInsert(ht, e1);
    ElemType e2 = {2, 10};
    TestInsert(ht, e2);
    ElemType e3 = {3, 20};
    TestInsert(ht, e3);
    TestInsert(ht, e3);

    TestSearch(ht, 1);
    TestSearch(ht, 2);
    TestSearch(ht, 3);
    TestSearch(ht, 4);

    TestDelete(ht, 1);
    TestSearch(ht, 1);
    TestDelete(ht, 2);
    TestDelete(ht, 2);
    TestSearch(ht, 3);

    return 0;
}