#include <stdio.h>
#include <stdlib.h>		// 提供malloc、realloc、free、exit原型
#include "SqList.h"

// 线性表L的初始化
Status InitList(SqList& L)
{
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	return OK;
}

// 销毁线性表L
void DestroyList(SqList& L)
{
	if (L.elem)
		delete L.elem;
}

// 清空线性表L
void ClearList(SqList& L)
{
	L.length = 0;
}

// 求线性表L的长度
int GetLength(SqList L)
{
	return L.length;
}

// 判断线性表L是否为空
Status IsEmpty(SqList L)
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

// 顺序表的取值
Status GetElem(SqList L, int i, ElemType& e)
{
	if (i < 1 || i > L.length)
		return ERROR;
	e = L.elem[i - 1];
	printf("第%d个元素为%d\n", i, e);
	return OK;
}

// 顺序表的查找
int LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
			return i + 1;	// 返回序号
	}
	return 0;
}

// 顺序表的插入
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

// 顺序表的删除
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
