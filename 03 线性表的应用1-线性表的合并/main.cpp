#include <stdio.h>
#include "SqList.h"

// 打印
void printElem(SqList L)
{
	if (L.length == 0)
	{
		printf("顺序表L为空\n");
		return;
	}
	printf("顺序表为：");
	for (int i = 0; i < L.length; i++)
		printf("%d ", L.elem[i]);
}

// 线性表的合并
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
		// 初始化
		if (InitList(La))
			printf("初始化顺序表La成功\n");
		else
			printf("初始化顺序表La失败\n");
		if (InitList(Lb))
			printf("初始化顺序表Lb成功\n");
		else
			printf("初始化顺序表Lb失败\n");

		printf("-------------------------------------------\n");
	}

	{
		// 插入
		printf("请输入La中的元素:\n");
		for (int i = 1; i <= 5; i++)
		{
			scanf_s("%d", &e);
			if (ListInsert(La, i, e))
				printf("插入La第%d个元素%d成功\n", i, e);
			else
				printf("插入La第%d个元素%d失败\n", i, e);
		}
		// 打印
		printElem(La);

		printf("\n\n请输入Lb中的元素:\n");
		for (int i = 1; i <= 5; i++)
		{
			scanf_s("%d", &e);
			if (ListInsert(Lb, i, e))
				printf("插入Lb第%d个元素%d成功\n", i, e);
			else
				printf("插入Lb第%d个元素%d失败\n", i, e);
		}
		// 打印
		printElem(Lb);

		printf("\n-------------------------------------------\n");
	}

	{
		// 合并
		unionList(La, Lb);

		// 打印
		printf("合并后的顺序表La如下\n");
		printElem(La);

		printf("\n-------------------------------------------\n");
	}

	{
		// 清空顺序表
		ClearList(La);
		ClearList(La);

		printf("清空顺序表La成功\n");
		printf("清空顺序表Lb成功\n");

		printf("-------------------------------------------\n");
	}

	{
		// 销毁顺序表
		DestroyList(La);
		DestroyList(Lb);

		printf("销毁顺序表La成功\n");
		printf("销毁顺序表Lb成功\n");
		printf("-------------------------------------------\n");
	}

	printf("\n");
	return 0;
}
