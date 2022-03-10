#include <stdlib.h>
#include "LinkQueue.h"

// �����г�ʼ��
Status InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(Qnode));
	if (!Q.front)
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

// ����������
Status DestroyQueue(LinkQueue& Q)
{
	while (Q.front)
	{
		QueuePtr p;
		p = Q.front->next;
		free(Q.front);
		Q.front = p;
	}
	return OK;
}

// ���������
Status EnQueue(LinkQueue& Q, QElemType e)
{
	QueuePtr p = new Qnode;
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

// �����г���
Status DeQueue(LinkQueue& Q, QElemType& e)
{
	if (Q.front == Q.rear)
		return ERROR;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	delete p;
	return OK;
}

// ���������ͷԪ��
QElemType GetHead(LinkQueue Q, QElemType& e)
{
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.front->next->data;
	return e;
}
