#include <stdlib.h>
#include "LinkStack.h"

// ��ջ�ĳ�ʼ��
Status InitStack(LinkStack& S)
{
	S = NULL;
	return OK;
}

// �ж���ջ�Ƿ�Ϊ��
Status StackEmpty(LinkStack S)
{
	if (S == NULL)
		return TRUE;
	else
		return FALSE;
}

// ��ջ����ջ
Status PushStack(LinkStack& S, SElemType e)
{
	LinkStack p;
	p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}

// ��ջ�ĳ�ջ
Status PopStack(LinkStack& S, SElemType& e)
{
	if (S == NULL)
		return ERROR;
	e = S->data;
	LinkStack p = S;
	S = S->next;
	delete p;
	return OK;
}

// ȡջ��Ԫ��
SElemType GetTop(LinkStack S)
{
	if (S)
		return S->data;
}
