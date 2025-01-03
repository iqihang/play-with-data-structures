#include <iostream>

#include "linklist.h"

using namespace std;

int main() {
    // 测试区域 开始

    // 创建链表节点
    LinkList p = new LNode;  // 分配一个类型为LNode的结点空间，用p指向这个结点
    p->data = 20;    // 为p结点的数据域赋值为20
    p->next = NULL;  // 新结点的指针域置空
    cout << p->data << endl;

    // 测试头插法创建链表
    ElemType a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkList L1 = CreateList(a, 9);
    PrintList(L1);

    // 测试尾插法创建链表
    LinkList L2 = CreateList2(a, 9);
    PrintList(L2);

    ElemType e;
    bool res;

    // 测试按序号查找
    res = GetElem(L1, 0, e);  // 测试边界条件
    cout << "查找第0个元素: ";
    if (res) {
        cout << "查找成功, 元素为: " << e << endl;
    } else {
        cout << "查找失败" << endl;
    }
    res = GetElem(L1, 9, e);  // 测试边界条件
    cout << "查找第9个元素: ";
    if (res) {
        cout << "查找成功, 元素为: " << e << endl;
    } else {
        cout << "查找失败" << endl;
    }
    res = GetElem(L1, 5, e);  // 测试正常情况
    cout << "查找第5个元素: ";
    if (res) {
        cout << "查找成功, 元素为: " << e << endl;
    } else {
        cout << "查找失败" << endl;
    }
    res = GetElem(L1, 10, e);  // 测试边界条件
    cout << "查找第10个元素: ";
    if (res) {
        cout << "查找成功, 元素为: " << e << endl;
    } else {
        cout << "查找失败" << endl;
    }

    // 测试按值查找
    LinkList resPtr;
    resPtr = LocateElem(L1, 1);  // 测试边界条件
    cout << "查找值为1的元素: ";
    if (resPtr) {
        cout << "查找成功" << endl;
    } else {
        cout << "查找失败" << endl;
    }
    resPtr = LocateElem(L1, 0);  // 测试边界条件
    cout << "查找值为0的元素: ";
    if (resPtr) {
        cout << "查找成功" << endl;
    } else {
        cout << "查找失败" << endl;
    }
    resPtr = LocateElem(L1, 6);  // 测试正常情况
    cout << "查找值为6的元素: ";
    if (resPtr) {
        cout << "查找成功" << endl;
    } else {
        cout << "查找失败" << endl;
    }

    // 测试区域 结束

    return 0;
}