#ifndef LINKSTACK_H
#define LINKSTACK_H

#include "Status.h"

// Ԫ�����Ͷ���
typedef int SElemType;

// ��ջ�Ķ���
typedef struct StackNode {
	SElemType data;
	struct StackNode* next;
}StackNode, *LinkStack;

// ��ջ�ĳ�ʼ��
Status InitStack(LinkStack& S);
// �ж���ջ�Ƿ�Ϊ��
Status StackEmpty(LinkStack S);
// ��ջ����ջ
Status PushStack(LinkStack& S, SElemType e);
// ��ջ�ĳ�ջ
Status PopStack(LinkStack& S, SElemType& e);
// ȡջ��Ԫ��
SElemType GetTop(LinkStack S);

#endif
