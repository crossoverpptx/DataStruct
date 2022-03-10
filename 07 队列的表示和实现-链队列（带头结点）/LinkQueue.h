#ifndef QUEUEPTR_H
#define QUEUEPTR_H

#include "Status.h"

// 元素类型定义
typedef int QElemType;

// 链式队列的定义
typedef struct Qnode{
	QElemType data;
	struct Qnode* next;
}Qnode, *QueuePtr;

typedef struct {
	QueuePtr front;	// 队头指针
	QueuePtr rear;	// 队尾指针
}LinkQueue;

// 链队列初始化
Status InitQueue(LinkQueue& Q);
// 销毁链队列
Status DestroyQueue(LinkQueue& Q);
// 链队列入队
Status EnQueue(LinkQueue& Q, QElemType e);
// 链队列出队
Status DeQueue(LinkQueue& Q, QElemType& e);
// 链队列求队头元素
Status GetHead(LinkQueue Q, QElemType& e);

#endif
