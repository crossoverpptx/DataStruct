#ifndef LINKLIST_H
#define LINKLIST_H

#include "Status.h"

// Ԫ�����Ͷ���
typedef int ElemType;

// ������Ķ���
typedef struct Lnode {
	ElemType data;
	struct Lnode *next;
}Lnode, *LinkList;

// ������ĳ�ʼ��
Status InitList(LinkList& L);
// �ж������Ƿ�Ϊ��
Status ListEmpty(LinkList L);
// �����������
Status DestroyList(LinkList& L);
// �������
Status ClearList(LinkList& L);
// ������ı�
int ListLength(LinkList L);
// ȡ�������i��Ԫ�ص�����
Status GetElem(LinkList L, int i, ElemType& e);
// ��ֵ����
int LocateElem(LinkList L, ElemType e);
// �ڵ�i���ڵ����ֵΪe���½ڵ�
Status ListInsert(LinkList& L, int i, ElemType e);
// ɾ����i���ڵ�
Status ListDelete(LinkList& L, int i, ElemType& e);
// ����������ͷ�巨
void CreatListHead(LinkList& L, int n);
// ����������β�巨
void CreatListEnd(LinkList& L, int n);

#endif
