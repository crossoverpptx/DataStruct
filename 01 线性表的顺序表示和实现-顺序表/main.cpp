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

int main()
{
	SqList L;

	{
		// 初始化
		if (InitList(L))
			printf("初始化顺序表L成功\n");
		else
			printf("初始化顺序表L失败\n");

		// 打印
		printElem(L);
		printf("-------------------------------------------\n");
	}

	{
		// 插入
		for (int i = 1; i <= 5; i++)
		{
			if (ListInsert(L, i, i + 1))
				printf("插入第%d个元素%d成功\n", i, i + 1);
			else
				printf("插入第%d个元素%d失败\n", i, i + 1);
		}

		// 打印
		printElem(L);
		printf("\n-------------------------------------------\n");
	}

	{
		// 判断线性表是否为空
		if(IsEmpty(L))
			printf("顺序表为空\n");
		else
			printf("顺序表不为空\n");
		printf("-------------------------------------------\n");
	}

	{
		// 求线性表L的长度
		printf("顺序表L的长度为：%d\n", GetLength(L));
		printf("-------------------------------------------\n");
	}

	{
		// 删除
		if(ListDelete(L, 3))
			printf("删除顺序表第3个元素成功\n");
		else
			printf("删除顺序表失败\n");

		// 打印
		printElem(L);
		printf("\n-------------------------------------------\n");
	}

	{
		// 顺序表的查找
		if(LocateElem(L, 5))
			printf("顺序表查找成功，元素5的序号为：%d\n", LocateElem(L, 5));
		else
			printf("顺序表查找失败\n");
		printf("-------------------------------------------\n");
	}

	{
		// 顺序表的取值
		ElemType e;
		if (GetElem(L, 3, e))
			printf("顺序表取值成功\n");
		else
			printf("顺序表取值失败\n");
		printf("-------------------------------------------\n");
	}

	{
		// 清空顺序表
		ClearList(L);

		printf("清空顺序表成功\n");

		// 打印
		printElem(L);
		printf("-------------------------------------------\n");
	}

	{
		// 销毁顺序表
		DestroyList(L);

		printf("销毁顺序表成功\n");
		printf("-------------------------------------------\n");
	}

	printf("\n");
	return 0;
}
