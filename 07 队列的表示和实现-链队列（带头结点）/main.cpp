#include <iostream>
#include <stdio.h>
#include "LinkQueue.h"

// ��ӡ
void PrintElem(LinkQueue Q)
{
	QueuePtr p;
	p = Q.front->next;
	std::cout << "����Ϊ��";
	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
}

int main()
{
	LinkQueue Q;
	QElemType e;

	{
		// ��ʼ��
		if (InitQueue(Q))
			printf("���ӳ�ʼ���ɹ�\n");
		else
			printf("���ӳ�ʼ��ʧ��\n");

		printf("--------------------------------------\n");
	}

	{
		// ���
		for (int i = 0; i < 5; i++)
		{
			printf("�������%d��Ԫ�أ�", i + 1);
			std::cin >> e;
			if(EnQueue(Q, e))
				printf("��ӵ�%d��Ԫ�� %d �ɹ�\n", i + 1, e);
			else
				printf("��ӵ�%d��Ԫ�� %d ʧ��\n", i + 1, e);
		}

		// ��ӡ
		PrintElem(Q);
		printf("\n--------------------------------------\n");
	}

	{
		// ��ͷԪ��
		printf("��ͷԪ��Ϊ��%d\n", GetHead(Q, e));

		printf("--------------------------------------\n");
	}

	{
		// ����
		if (DeQueue(Q, e))
			printf("���ӳɹ���Ԫ��Ϊ��%d\n", e);
		else
			printf("����ʧ�ܣ�Ԫ��Ϊ��%d\n", e);

		// ��ӡ
		PrintElem(Q);
		printf("\n--------------------------------------\n");
	}

	{
		// ����
		if (DestroyQueue(Q))
			printf("�������ٳɹ�\n");
		else
			printf("��������ʧ��\n");

		printf("--------------------------------------\n");
	}

	return 0;
}
