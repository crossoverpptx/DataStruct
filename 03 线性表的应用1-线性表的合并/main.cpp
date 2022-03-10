#include <stdio.h>
#include "SqList.h"

// ��ӡ
void printElem(SqList L)
{
	if (L.length == 0)
	{
		printf("˳���LΪ��\n");
		return;
	}
	printf("˳���Ϊ��");
	for (int i = 0; i < L.length; i++)
		printf("%d ", L.elem[i]);
}

// ���Ա�ĺϲ�
void unionList(SqList& La, SqList Lb)
{
	//int La_len = GetLength(La);
	int Lb_len = GetLength(Lb);

	for (int i = 0; i < Lb_len; i++)
	{
		if (LocateElem(La, Lb.elem[i]))
			continue;
		else
			ListInsert(La, GetLength(La) + 1, Lb.elem[i]);
	}
}

int main()
{
	SqList La, Lb;
	ElemType e;

	{
		// ��ʼ��
		if (InitList(La))
			printf("��ʼ��˳���La�ɹ�\n");
		else
			printf("��ʼ��˳���Laʧ��\n");
		if (InitList(Lb))
			printf("��ʼ��˳���Lb�ɹ�\n");
		else
			printf("��ʼ��˳���Lbʧ��\n");

		printf("-------------------------------------------\n");
	}

	{
		// ����
		printf("������La�е�Ԫ��:\n");
		for (int i = 1; i <= 5; i++)
		{
			scanf_s("%d", &e);
			if (ListInsert(La, i, e))
				printf("����La��%d��Ԫ��%d�ɹ�\n", i, e);
			else
				printf("����La��%d��Ԫ��%dʧ��\n", i, e);
		}
		// ��ӡ
		printElem(La);

		printf("\n\n������Lb�е�Ԫ��:\n");
		for (int i = 1; i <= 5; i++)
		{
			scanf_s("%d", &e);
			if (ListInsert(Lb, i, e))
				printf("����Lb��%d��Ԫ��%d�ɹ�\n", i, e);
			else
				printf("����Lb��%d��Ԫ��%dʧ��\n", i, e);
		}
		// ��ӡ
		printElem(Lb);

		printf("\n-------------------------------------------\n");
	}

	{
		// �ϲ�
		unionList(La, Lb);

		// ��ӡ
		printf("�ϲ����˳���La����\n");
		printElem(La);

		printf("\n-------------------------------------------\n");
	}

	{
		// ���˳���
		ClearList(La);
		ClearList(La);

		printf("���˳���La�ɹ�\n");
		printf("���˳���Lb�ɹ�\n");

		printf("-------------------------------------------\n");
	}

	{
		// ����˳���
		DestroyList(La);
		DestroyList(Lb);

		printf("����˳���La�ɹ�\n");
		printf("����˳���Lb�ɹ�\n");
		printf("-------------------------------------------\n");
	}

	printf("\n");
	return 0;
}
