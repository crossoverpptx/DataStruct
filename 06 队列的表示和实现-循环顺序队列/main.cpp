#include <stdio.h>
#include "SqQueue.h"

int main()
{
	SqQueue Q;
	QElemType e;

	{
		// ��ʼ��
		if (InitQueue(Q))
			printf("ѭ�����г�ʼ���ɹ�\n");
		else
			printf("ѭ�����г�ʼ��ʧ��\n");

		printf("------------------------------");
	}

	{
		// ѭ���������
		for (int i = 0; i < 5; i++)
		{
			printf("�������%d�����Ԫ�أ�", i + 1);
			scanf_s("%d", &e);
			if (EnQueue(Q, e))
				printf("��%d��Ԫ�� %d ��ӳɹ�\n", i + 1, e);
			else
				printf("��%d��Ԫ�� %d ���ʧ��\n", i + 1, e);
		}

		printf("------------------------------");
	}
	
	{
		// ����г���
		printf("ѭ�����г���Ϊ��%d\n", QueueLength(Q));

		printf("------------------------------");
	}

	return 0;
}
