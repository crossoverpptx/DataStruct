#include <stdlib.h>
#include "SqQueue.h"

// ѭ�����еĳ�ʼ��
Status InitQueue(SqQueue& Q)
{
	Q.base = new QElemType[MAXQSIZE];
	if (Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

// ����еĳ���
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

// ѭ���������
Status EnQueue(SqQueue& Q, QElemType e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)	// ����
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;	// ��βָ��+1
	return OK;
}

// ѭ�����г���
Status DeQueue(SqQueue& Q, QElemType& e)
{
	if (Q.front == Q.rear)	// �ӿ�
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;	// ��ͷָ��+1
	return OK;
}

// ȡ��ͷԪ��
QElemType GetHead(SqQueue Q)
{
	if (Q.front != Q.rear)
		return Q.base[Q.front];
}
