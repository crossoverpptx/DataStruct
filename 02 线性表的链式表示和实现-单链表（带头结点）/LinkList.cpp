#include <stdio.h>
#include <stddef.h>
#include "LinkList.h"

// 单链表的初始化
Status InitList(LinkList& L)
{
	L = new Lnode;
	L->next = NULL;
	return OK;
}

// 判断链表是否为空
Status ListEmpty(LinkList L)
{
	if (L->next)
		return FALSE;
	else
		return TRUE;
}

// 单链表的销毁
Status DestroyList(LinkList& L)
{
	LinkList p;
	while (L)
	{ 
		p = L;
		L = L->next;
		delete p;
	}
	return OK;
}

// 清空链表
Status ClearList(LinkList& L)
{
	LinkList p, q;
	p = L->next;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
	return OK;
}

// 求单链表的表长
int ListLength(LinkList L)
{
	LinkList p;
	p = L->next;
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

// 取单链表第i个元素的内容
Status GetElem(LinkList L, int i, ElemType& e)
{
	LinkList p;
	int j = 1;
	p = L->next;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	e = p->data;
	printf("单链表第%d个元素的值为：%d\n", i, e);
	return OK;
}

// 按值查找
int LocateElem(LinkList L, ElemType e)
{
	LinkList p;
	int j = 1;
	p = L->next;
	while (p && p->data != e)
	{
		p = p->next;
		j++;
	}
	if (p)
		return j;
	else
		return 0;
}

// 在第i个节点插入值为e的新节点
Status ListInsert(LinkList& L, int i, ElemType e)
{
	LinkList p, s;
	int j = 0;
	p = L;
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		return ERROR;
	s = new Lnode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

// 删除第i个节点
Status ListDelete(LinkList& L, int i, ElemType& e)
{
	LinkList p, q;
	int j = 0;
	p = L;
	while (p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1)
		return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data;
	delete q;
	return OK;
}

// 建立单链表：头插法
void CreatListHead(LinkList& L, int n)
{
	L = new Lnode;
	L->next = NULL;
	Lnode* p;
	for (int i = 0; i < n; ++i)
	{
		ElemType node_data;
		p = new Lnode;
		scanf_s("%d", &node_data);
		p->data = node_data;
		p->next = L->next;
		L->next = p;
	}
}

// 建立单链表：尾插法
void CreatListEnd(LinkList& L, int n)
{
	L = new Lnode;
	L->next = NULL;
	Lnode* p, *end;
	end = L;
	for (int i = 0; i < n; ++i)
	{
		ElemType node_data;
		p = new Lnode;
		scanf_s("%d", &node_data);
		p->data = node_data;
		end->next = p;
		end = p;
	}
	end->next = NULL;
}