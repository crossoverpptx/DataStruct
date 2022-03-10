#include <stdio.h>
#include "LinkStack.h"

int main()
{
	LinkStack S;

	{
		// 链栈的初始化
		if (InitStack(S))
			printf("链栈初始化成功\n");
		else
			printf("链栈初始化失败\n");

		printf("-------------------------------------\n");
	}

	return 0;
}
