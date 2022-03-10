#ifndef SQLIST_H
#define SQLIST_H

#include "Status.h"

// �궨��
#define MAXSIZE 100

// Ԫ�����Ͷ���
typedef int ElemType;

// ���Ա�Ķ���
typedef struct {
	ElemType* elem;
	int length;
}SqList;

// ���Ա�L�ĳ�ʼ��
Status InitList(SqList& L);
// �������Ա�L
void DestroyList(SqList& L);
// ������Ա�L
void ClearList(SqList& L);
// �����Ա�L�ĳ���
int GetLength(SqList L);
// �ж����Ա�L�Ƿ�Ϊ��
int IsEmpty(SqList L);
// ˳����ȡֵ
int GetElem(SqList L, int i, ElemType& e);
// ˳���Ĳ���
int LocateElem(SqList L, ElemType e);
// ˳���Ĳ���
Status ListInsert(SqList& L, int i, ElemType e);
// ˳����ɾ��
Status ListDelete(SqList& L, int i);

#endif
