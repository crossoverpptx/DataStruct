#ifndef SQSTACK_H
#define SQSTACK_H

#include "Status.h"

// �궨��
#define MAXSIZE 100

// Ԫ�����Ͷ���
typedef int SElemType;

// ˳��ջ�Ķ���
typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

// ˳��ջ�ĳ�ʼ��
Status InitStack(SqStack& S);
// �ж�˳��ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack S);
// ��˳��ջ�ĳ���
int StackLength(SqStack S);
// ���˳��ջ
Status ClearStack(SqStack& S);
// ����˳��ջ
Status DestroyStack(SqStack& S);
// ˳��ջ����ջ
Status PushStack(SqStack& S, SElemType e);
// ˳��ջ�ĳ�ջ
Status PopStack(SqStack& S, SElemType& e);

#endif
