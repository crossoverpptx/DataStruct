#include <stdlib.h>
#include "LinkStack.h"

// Á´Õ»µÄ³õÊ¼»¯
Status InitStack(LinkStack& S)
{
	S = NULL;
	return OK;
}

// ÅÐ¶ÏÁ´Õ»ÊÇ·ñÎª¿Õ
Status StackEmpty(LinkStack S)
{
	if (S == NULL)
		return TRUE;
	else
		return FALSE;
}

// Á´Õ»µÄÈëÕ»
Status PushStack(LinkStack& S, SElemType e)
{
	LinkStack p;
	p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}

// Á´Õ»µÄ³öÕ»
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

// È¡Õ»¶¥ÔªËØ
SElemType GetTop(LinkStack S)
{
	if (S)
		return S->data;
}
