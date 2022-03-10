#ifndef LINKLIST_H
#define LINKLIST_H

#include "Status.h"

// 元素类型定义
typedef int ElemType;

// 单链表的定义
typedef struct Lnode {
	ElemType data;
	struct Lnode *next;
}Lnode, *LinkList;

// 单链表的初始化
Status InitList(LinkList& L);
// 判断链表是否为空
Status ListEmpty(LinkList L);
// 单链表的销毁
Status DestroyList(LinkList& L);
// 清空链表
Status ClearList(LinkList& L);
// 求单链表的表长
int ListLength(LinkList L);
// 取单链表第i个元素的内容
Status GetElem(LinkList L, int i, ElemType& e);
// 按值查找
int LocateElem(LinkList L, ElemType e);
// 在第i个节点插入值为e的新节点
Status ListInsert(LinkList& L, int i, ElemType e);
// 删除第i个节点
Status ListDelete(LinkList& L, int i, ElemType& e);
// 建立单链表：头插法
void CreatListHead(LinkList& L, int n);
// 建立单链表：尾插法
void CreatListEnd(LinkList& L, int n);

#endif
