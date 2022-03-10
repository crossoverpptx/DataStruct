#include <stdio.h>
#include "LinkList.h"

void Illustrate(LinkList L)
{
	printf("单链表为：");
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
		// 初始化
		if (InitList(L))
			printf("单链表初始化成功\n");
		else
			printf("单链表初始化失败\n");

		printf("-----------------------------------------\n");
	}

	{
		// 创建单链表：尾插法，按输入顺序排列
		CreatListEnd(L, 5);
		printf("单链表创建成功\n");

		// 打印
		Illustrate(L);
		printf("\n-----------------------------------------\n");
	}

	{
		// 判断链表是否为空
		if(ListEmpty(L))
			printf("单链表为空\n");
		else
			printf("单链表不为空\n");

		printf("-----------------------------------------\n");
	}

	{
		// 求单链表的表长
		printf("单链表长度为：%d\n", ListLength(L));

		printf("-----------------------------------------\n");
	}

	{
		// 取单链表第i个元素的内容
		if (GetElem(L, 3, e))
			printf("单链表取值成功\n");
		else
			printf("单链表取值失败\n");

		printf("-----------------------------------------\n");
	}	
	
	{
		// 按值查找
		if (LocateElem(L, 5))
			printf("单链表查找成功，元素5的序号为：%d\n", LocateElem(L, 5));
		else
			printf("单链表查找失败\n");

		printf("-----------------------------------------\n");
	}

	{
		// 在第i个节点插入值为e的新节点
		if (ListInsert(L, 3, 99))
			printf("单链表插入成功\n");
		else
			printf("单链表插入失败\n");

		// 打印
		Illustrate(L);
		printf("\n-----------------------------------------\n");
	}

	{
		// 删除第i个节点
		if (ListDelete(L, 3, e))
			printf("单链表删除成功，删除的元素为：%d\n", e);
		else
			printf("单链表删除失败\n");

		// 打印
		Illustrate(L);
		printf("\n-----------------------------------------\n");
	}

	{
		// 清空链表
		if(ClearList(L))
			printf("清空单链表成功\n");
		else
			printf("清空单链表失败\n");

		if (ListEmpty(L))
			printf("单链表为空\n");
		else
			printf("单链表不为空\n");
		printf("-----------------------------------------\n");
	}

	{
		// 单链表的销毁
		if (DestroyList(L))
			printf("销毁单链表成功\n");
		else
			printf("销毁单链表失败\n");

		printf("-----------------------------------------\n");
	}

	return 0;
}
