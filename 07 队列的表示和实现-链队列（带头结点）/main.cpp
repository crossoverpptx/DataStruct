#include <iostream>
#include <stdio.h>
#include "LinkQueue.h"

// 打印
void PrintElem(LinkQueue Q)
{
	QueuePtr p;
	p = Q.front->next;
	std::cout << "链队为：";
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
		// 初始化
		if (InitQueue(Q))
			printf("链队初始化成功\n");
		else
			printf("链队初始化失败\n");

		printf("--------------------------------------\n");
	}

	{
		// 入队
		for (int i = 0; i < 5; i++)
		{
			printf("请输入第%d个元素：", i + 1);
			std::cin >> e;
			if(EnQueue(Q, e))
				printf("入队第%d个元素 %d 成功\n", i + 1, e);
			else
				printf("入队第%d个元素 %d 失败\n", i + 1, e);
		}

		// 打印
		PrintElem(Q);
		printf("\n--------------------------------------\n");
	}

	{
		// 队头元素
		printf("队头元素为：%d\n", GetHead(Q, e));

		printf("--------------------------------------\n");
	}

	{
		// 出队
		if (DeQueue(Q, e))
			printf("出队成功，元素为：%d\n", e);
		else
			printf("出队失败，元素为：%d\n", e);

		// 打印
		PrintElem(Q);
		printf("\n--------------------------------------\n");
	}

	{
		// 销毁
		if (DestroyQueue(Q))
			printf("链队销毁成功\n");
		else
			printf("链队销毁失败\n");

		printf("--------------------------------------\n");
	}

	return 0;
}
