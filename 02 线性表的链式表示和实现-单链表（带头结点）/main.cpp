#include <stdio.h>
#include "LinkList.h"

void Illustrate(LinkList L)
{
	printf("������Ϊ��");
	LinkList tem = L;
	while (tem->next)
	{
		tem = tem->next;
		printf("%d ", tem->data);
	}
}

int main()
{
	LinkList L;
	ElemType e;

	{
		// ��ʼ��
		if (InitList(L))
			printf("�������ʼ���ɹ�\n");
		else
			printf("�������ʼ��ʧ��\n");

		printf("-----------------------------------------\n");
	}

	{
		// ����������β�巨��������˳������
		CreatListEnd(L, 5);
		printf("���������ɹ�\n");

		// ��ӡ
		Illustrate(L);
		printf("\n-----------------------------------------\n");
	}

	{
		// �ж������Ƿ�Ϊ��
		if(ListEmpty(L))
			printf("������Ϊ��\n");
		else
			printf("������Ϊ��\n");

		printf("-----------------------------------------\n");
	}

	{
		// ������ı�
		printf("��������Ϊ��%d\n", ListLength(L));

		printf("-----------------------------------------\n");
	}

	{
		// ȡ�������i��Ԫ�ص�����
		if (GetElem(L, 3, e))
			printf("������ȡֵ�ɹ�\n");
		else
			printf("������ȡֵʧ��\n");

		printf("-----------------------------------------\n");
	}	
	
	{
		// ��ֵ����
		if (LocateElem(L, 5))
			printf("��������ҳɹ���Ԫ��5�����Ϊ��%d\n", LocateElem(L, 5));
		else
			printf("���������ʧ��\n");

		printf("-----------------------------------------\n");
	}

	{
		// �ڵ�i���ڵ����ֵΪe���½ڵ�
		if (ListInsert(L, 3, 99))
			printf("���������ɹ�\n");
		else
			printf("���������ʧ��\n");

		// ��ӡ
		Illustrate(L);
		printf("\n-----------------------------------------\n");
	}

	{
		// ɾ����i���ڵ�
		if (ListDelete(L, 3, e))
			printf("������ɾ���ɹ���ɾ����Ԫ��Ϊ��%d\n", e);
		else
			printf("������ɾ��ʧ��\n");

		// ��ӡ
		Illustrate(L);
		printf("\n-----------------------------------------\n");
	}

	{
		// �������
		if(ClearList(L))
			printf("��յ�����ɹ�\n");
		else
			printf("��յ�����ʧ��\n");

		if (ListEmpty(L))
			printf("������Ϊ��\n");
		else
			printf("������Ϊ��\n");
		printf("-----------------------------------------\n");
	}

	{
		// �����������
		if (DestroyList(L))
			printf("���ٵ�����ɹ�\n");
		else
			printf("���ٵ�����ʧ��\n");

		printf("-----------------------------------------\n");
	}

	return 0;
}
