#include <stdio.h>
#include <stddef.h>
#include "LinkList.h"

// ������ĳ�ʼ��
Status InitList(LinkList& L)
{
	L = new Lnode;
	L->next = NULL;
	return OK;
}

// �ж������Ƿ�Ϊ��
Status ListEmpty(LinkList L)
{
	if (L->next)
		return FALSE;
	else
		return TRUE;
}

// �����������
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

// �������
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

// ������ı�
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

// ȡ�������i��Ԫ�ص�����
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
	printf("�������%d��Ԫ�ص�ֵΪ��%d\n", i, e);
	return OK;
}

// ��ֵ����
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

// �ڵ�i���ڵ����ֵΪe���½ڵ�
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

// ɾ����i���ڵ�
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

// ����������ͷ�巨
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

// ����������β�巨
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