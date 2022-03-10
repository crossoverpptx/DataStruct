#include <stdio.h>
#include <stdlib.h>		// �ṩmalloc��realloc��free��exitԭ��
#include "SqList.h"

// ���Ա�L�ĳ�ʼ��
Status InitList(SqList& L)
{
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	return OK;
}

// �������Ա�L
void DestroyList(SqList& L)
{
	if (L.elem)
		delete L.elem;
}

// ������Ա�L
void ClearList(SqList& L)
{
	L.length = 0;
}

// �����Ա�L�ĳ���
int GetLength(SqList L)
{
	return L.length;
}

// �ж����Ա�L�Ƿ�Ϊ��
Status IsEmpty(SqList L)
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

// ˳����ȡֵ
Status GetElem(SqList L, int i, ElemType& e)
{
	if (i < 1 || i > L.length)
		return ERROR;
	e = L.elem[i - 1];
	printf("��%d��Ԫ��Ϊ%d\n", i, e);
	return OK;
}

// ˳���Ĳ���
int LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
			return i + 1;	// �������
	}
	return 0;
}

// ˳���Ĳ���
Status ListInsert(SqList& L, int i, ElemType e)
{
	if (i < 1 || i > L.length + 1)
		return ERROR;
	if (L.length == MAXSIZE)
		return ERROR;
	for (int j = L.length - 1; j >= i - 1; j--)
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}

// ˳����ɾ��
Status ListDelete(SqList& L, int i)
{
	if (i < 1 || i > L.length)
		return ERROR;
	for (int j = i; j <= L.length - 1; j++)
	{
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}
