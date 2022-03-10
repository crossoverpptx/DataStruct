#ifndef SQQUEUE_H
#define SQQUEUE_H

#include "Status.h"

#define MAXQSIZE 10

// Ԫ�����Ͷ���
typedef int QElemType;

// ѭ�����еĶ���
typedef struct {
	QElemType* base;
	int front;	// ͷָ��
	int rear;	// βָ��
}SqQueue;

// ѭ�����еĳ�ʼ��
Status InitQueue(SqQueue& Q);
// ����еĳ���
int QueueLength(SqQueue Q);
// ѭ���������
Status EnQueue(SqQueue& Q, QElemType e);
// ѭ�����г���
Status DeQueue(SqQueue& Q, QElemType& e);
// ȡ��ͷԪ��
QElemType GetHead(SqQueue Q);

#endif
