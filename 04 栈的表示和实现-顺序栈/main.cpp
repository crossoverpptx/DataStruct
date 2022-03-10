#include <stdio.h>
#include "SqStack.h"

// 打印
void printElem(SqStack S)
{
	SElemType* p = S.base;
	printf("顺序栈为：");
	for (p; p < S.top; p++)
		printf("%d ", *p);
}

int main()
{
	SqStack S;
	SElemType e, f;

	{
		// 顺序栈的初始化
		if (InitStack(S))
			printf("顺序栈初始化成功\n");
		else
			printf("顺序栈初始化失败\n");

		printf("-----------------------------------------\n");
	}

	{
		// 顺序栈的入栈
		for (int i = 0; i < 5; i++)
		{
			printf("请输入第%d个入栈元素：", i + 1);
			scanf_s("%d", &e);
			if (PushStack(S, e))
				printf("输入第%d个元素 %d 成功\n", i + 1, e);
			else
				printf("输入第%d个元素 %d 失败\n", i + 1, e);
		}

		printf("\n");
		// 打印
		printElem(S);
		printf("\n-----------------------------------------\n");
	}

	{
		// 判断顺序栈是否为空
		if (StackEmpty(S))
			printf("顺序栈为空\n");
		else
			printf("顺序栈不为空\n");

		printf("-----------------------------------------\n");
	}

	{
		// 求顺序栈的长度
		printf("顺序栈的长度为：%d\n", StackLength(S));

		printf("-----------------------------------------\n");
	}

	{
		// 顺序栈的出栈
		if (PopStack(S, f))
			printf("顺序栈出栈成功，出栈元素为：%d\n", f);
		else
			printf("顺序栈出栈失败\n");

		printf("\n");
		// 打印
		printElem(S);
		printf("\n-----------------------------------------\n");
	}

	{
		// 求顺序栈的长度
		printf("顺序栈的长度为：%d\n", StackLength(S));

		printf("-----------------------------------------\n");
	}

	{
		// 清空顺序表
		if (ClearStack(S))
			printf("清空顺序栈成功\n");
		else
			printf("清空顺序栈失败\n");

		printf("-----------------------------------------\n");
	}

	{
		// 销毁顺序栈
		if (DestroyStack(S))
			printf("销毁顺序栈成功\n");
		else
			printf("销毁顺序栈失败\n");

		printf("-----------------------------------------\n");
	}
	return 0;
}
