#include <stdio.h>
#include "SqStack.h"

// ��ӡ
void printElem(SqStack S)
{
	SElemType* p = S.base;
	printf("˳��ջΪ��");
	for (p; p < S.top; p++)
		printf("%d ", *p);
}

int main()
{
	SqStack S;
	SElemType e, f;

	{
		// ˳��ջ�ĳ�ʼ��
		if (InitStack(S))
			printf("˳��ջ��ʼ���ɹ�\n");
		else
			printf("˳��ջ��ʼ��ʧ��\n");

		printf("-----------------------------------------\n");
	}

	{
		// ˳��ջ����ջ
		for (int i = 0; i < 5; i++)
		{
			printf("�������%d����ջԪ�أ�", i + 1);
			scanf_s("%d", &e);
			if (PushStack(S, e))
				printf("�����%d��Ԫ�� %d �ɹ�\n", i + 1, e);
			else
				printf("�����%d��Ԫ�� %d ʧ��\n", i + 1, e);
		}

		printf("\n");
		// ��ӡ
		printElem(S);
		printf("\n-----------------------------------------\n");
	}

	{
		// �ж�˳��ջ�Ƿ�Ϊ��
		if (StackEmpty(S))
			printf("˳��ջΪ��\n");
		else
			printf("˳��ջ��Ϊ��\n");

		printf("-----------------------------------------\n");
	}

	{
		// ��˳��ջ�ĳ���
		printf("˳��ջ�ĳ���Ϊ��%d\n", StackLength(S));

		printf("-----------------------------------------\n");
	}

	{
		// ˳��ջ�ĳ�ջ
		if (PopStack(S, f))
			printf("˳��ջ��ջ�ɹ�����ջԪ��Ϊ��%d\n", f);
		else
			printf("˳��ջ��ջʧ��\n");

		printf("\n");
		// ��ӡ
		printElem(S);
		printf("\n-----------------------------------------\n");
	}

	{
		// ��˳��ջ�ĳ���
		printf("˳��ջ�ĳ���Ϊ��%d\n", StackLength(S));

		printf("-----------------------------------------\n");
	}

	{
		// ���˳���
		if (ClearStack(S))
			printf("���˳��ջ�ɹ�\n");
		else
			printf("���˳��ջʧ��\n");

		printf("-----------------------------------------\n");
	}

	{
		// ����˳��ջ
		if (DestroyStack(S))
			printf("����˳��ջ�ɹ�\n");
		else
			printf("����˳��ջʧ��\n");

		printf("-----------------------------------------\n");
	}
	return 0;
}
