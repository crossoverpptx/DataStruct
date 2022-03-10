#include <stdio.h>
#include "SqQueue.h"

int main()
{
	SqQueue Q;
	QElemType e;

	{
		// 初始化
		if (InitQueue(Q))
			printf("循环队列初始化成功\n");
		else
			printf("循环队列初始化失败\n");

		printf("------------------------------");
	}

	{
		// 循环队列入队
		for (int i = 0; i < 5; i++)
		{
			printf("请输入第%d个入队元素：", i + 1);
			scanf_s("%d", &e);
			if (EnQueue(Q, e))
				printf("第%d个元素 %d 入队成功\n", i + 1, e);
			else
				printf("第%d个元素 %d 入队失败\n", i + 1, e);
		}

		printf("------------------------------");
	}
	
	{
		// 求队列长度
		printf("循环队列长度为：%d\n", QueueLength(Q));

		printf("------------------------------");
	}

	return 0;
}
