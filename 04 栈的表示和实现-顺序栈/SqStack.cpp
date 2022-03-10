#include <stdlib.h>
#include "SqStack.h"

// ˳��ջ�ĳ�ʼ��
Status InitStack(SqStack& S)
{
	S.base = new SElemType[MAXSIZE];
	// ������c���Եķ��䷽ʽ
	//S.base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));
	if (!S.base)	exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

// �ж�˳��ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

// ��˳��ջ�ĳ���
int StackLength(SqStack S)
{
	return (int)(S.top - S.base);
}

// ���˳���
Status ClearStack(SqStack& S)
{
	if (S.base)
		S.top = S.base;
	return OK;
}

// ����˳��ջ
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

// ˳��ջ����ջ
Status PushStack(SqStack& S, SElemType e)
{
	if (S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++ = e;
	return OK;
}

// ˳��ջ�ĳ�ջ
Status PopStack(SqStack& S, SElemType& e)
{
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}
