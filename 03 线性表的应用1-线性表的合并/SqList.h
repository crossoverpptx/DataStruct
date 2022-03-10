#ifndef SQLIST_H
#define SQLIST_H

#include "Status.h"

// 宏定义
#define MAXSIZE 100

// 元素类型定义
typedef int ElemType;

// 线性表的定义
typedef struct {
	ElemType* elem;
	int length;
}SqList;

// 线性表L的初始化
Status InitList(SqList& L);
// 销毁线性表L
void DestroyList(SqList& L);
// 清空线性表L
void ClearList(SqList& L);
// 求线性表L的长度
int GetLength(SqList L);
// 判断线性表L是否为空
int IsEmpty(SqList L);
// 顺序表的取值
int GetElem(SqList L, int i, ElemType& e);
// 顺序表的查找
int LocateElem(SqList L, ElemType e);
// 顺序表的插入
Status ListInsert(SqList& L, int i, ElemType e);
// 顺序表的删除
Status ListDelete(SqList& L, int i);

#endif
