#include <stdio.h>
#include "LinkStack.h"

int main()
{
	LinkStack S;

	{
		// ��ջ�ĳ�ʼ��
		if (InitStack(S))
			printf("��ջ��ʼ���ɹ�\n");
		else
			printf("��ջ��ʼ��ʧ��\n");

		printf("-------------------------------------\n");
	}

	return 0;
}
