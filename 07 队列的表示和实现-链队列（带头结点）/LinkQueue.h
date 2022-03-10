#ifndef QUEUEPTR_H
#define QUEUEPTR_H

#include "Status.h"

// Ԫ�����Ͷ���
typedef int QElemType;

// ��ʽ���еĶ���
typedef struct Qnode{
	QElemType data;
	struct Qnode* next;
}Qnode, *QueuePtr;

typedef struct {
	QueuePtr front;	// ��ͷָ��
	QueuePtr rear;	// ��βָ��
}LinkQueue;

// �����г�ʼ��
Status InitQueue(LinkQueue& Q);
// ����������
Status DestroyQueue(LinkQueue& Q);
// ���������
Status EnQueue(LinkQueue& Q, QElemType e);
// �����г���
Status DeQueue(LinkQueue& Q, QElemType& e);
// ���������ͷԪ��
Status GetHead(LinkQueue Q, QElemType& e);

#endif
