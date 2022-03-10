#ifndef SQQUEUE_H
#define SQQUEUE_H

#include "Status.h"

#define MAXQSIZE 10

// 元素类型定义
typedef int QElemType;

// 循环队列的定义
typedef struct {
	QElemType* base;
	int front;	// 头指针
	int rear;	// 尾指针
}SqQueue;

// 循环队列的初始化
Status InitQueue(SqQueue& Q);
// 求队列的长度
int QueueLength(SqQueue Q);
// 循环队列入队
Status EnQueue(SqQueue& Q, QElemType e);
// 循环队列出队
Status DeQueue(SqQueue& Q, QElemType& e);
// 取队头元素
QElemType GetHead(SqQueue Q);

#endif
