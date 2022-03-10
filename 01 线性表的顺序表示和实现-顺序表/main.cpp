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

int main()
{
	SqList L;

	{
		// ��ʼ��
		if (InitList(L))
			printf("��ʼ��˳���L�ɹ�\n");
		else
			printf("��ʼ��˳���Lʧ��\n");

		// ��ӡ
		printElem(L);
		printf("-------------------------------------------\n");
	}

	{
		// ����
		for (int i = 1; i <= 5; i++)
		{
			if (ListInsert(L, i, i + 1))
				printf("�����%d��Ԫ��%d�ɹ�\n", i, i + 1);
			else
				printf("�����%d��Ԫ��%dʧ��\n", i, i + 1);
		}

		// ��ӡ
		printElem(L);
		printf("\n-------------------------------------------\n");
	}

	{
		// �ж����Ա��Ƿ�Ϊ��
		if(IsEmpty(L))
			printf("˳���Ϊ��\n");
		else
			printf("˳���Ϊ��\n");
		printf("-------------------------------------------\n");
	}

	{
		// �����Ա�L�ĳ���
		printf("˳���L�ĳ���Ϊ��%d\n", GetLength(L));
		printf("-------------------------------------------\n");
	}

	{
		// ɾ��
		if(ListDelete(L, 3))
			printf("ɾ��˳����3��Ԫ�سɹ�\n");
		else
			printf("ɾ��˳���ʧ��\n");

		// ��ӡ
		printElem(L);
		printf("\n-------------------------------------------\n");
	}

	{
		// ˳���Ĳ���
		if(LocateElem(L, 5))
			printf("˳�����ҳɹ���Ԫ��5�����Ϊ��%d\n", LocateElem(L, 5));
		else
			printf("˳������ʧ��\n");
		printf("-------------------------------------------\n");
	}

	{
		// ˳����ȡֵ
		ElemType e;
		if (GetElem(L, 3, e))
			printf("˳���ȡֵ�ɹ�\n");
		else
			printf("˳���ȡֵʧ��\n");
		printf("-------------------------------------------\n");
	}

	{
		// ���˳���
		ClearList(L);

		printf("���˳���ɹ�\n");

		// ��ӡ
		printElem(L);
		printf("-------------------------------------------\n");
	}

	{
		// ����˳���
		DestroyList(L);

		printf("����˳���ɹ�\n");
		printf("-------------------------------------------\n");
	}

	printf("\n");
	return 0;
}
