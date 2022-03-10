#include <stdlib.h>
#include "LinkQueue.h"

// 链队列初始化
Status InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(Qnode));
	if (!Q.front)
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

// 销毁链队列
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

// 链队列入队
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

// 链队列出队
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

// 链队列求队头元素
QElemType GetHead(LinkQueue Q, QElemType& e)
{
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.front->next->data;
	return e;
}
