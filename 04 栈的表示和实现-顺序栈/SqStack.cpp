#include <stdlib.h>
#include "SqStack.h"

// 顺序栈的初始化
Status InitStack(SqStack& S)
{
	S.base = new SElemType[MAXSIZE];
	// 或者用c语言的分配方式
	//S.base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));
	if (!S.base)	exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

// 判断顺序栈是否为空
Status StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

// 求顺序栈的长度
int StackLength(SqStack S)
{
	return (int)(S.top - S.base);
}

// 清空顺序表
Status ClearStack(SqStack& S)
{
	if (S.base)
		S.top = S.base;
	return OK;
}

// 销毁顺序栈
Status DestroyStack(SqStack& S)
{
	if (S.base)
	{
		delete S.base;
		S.stacksize = 0;
		S.base = S.top = NULL;
	}
	return OK;
}

// 顺序栈的入栈
Status PushStack(SqStack& S, SElemType e)
{
	if (S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++ = e;
	return OK;
}

// 顺序栈的出栈
Status PopStack(SqStack& S, SElemType& e)
{
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}
