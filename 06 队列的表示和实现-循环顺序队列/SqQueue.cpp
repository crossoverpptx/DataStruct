#include <stdlib.h>
#include "SqQueue.h"

// 循环队列的初始化
Status InitQueue(SqQueue& Q)
{
	Q.base = new QElemType[MAXQSIZE];
	if (Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

// 求队列的长度
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

// 循环队列入队
Status EnQueue(SqQueue& Q, QElemType e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)	// 队满
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;	// 队尾指针+1
	return OK;
}

// 循环队列出队
Status DeQueue(SqQueue& Q, QElemType& e)
{
	if (Q.front == Q.rear)	// 队空
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;	// 队头指针+1
	return OK;
}

// 取队头元素
QElemType GetHead(SqQueue Q)
{
	if (Q.front != Q.rear)
		return Q.base[Q.front];
}
