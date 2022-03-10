#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 255

typedef unsigned char SString[MAXLEN + 1];       // 0号单元存放串的长度

/*
 * 初始化，构造一个值为chars的串T。
 */
void StrAssign(SString S, const char* chars)
{
	int len = (int)strlen(chars);
	S[0] = len;
	for (int i = 1; i <= len; i++)
	{
		S[i] = chars[i - 1];
	}
}

// 测试函数，打印字符串
void PrintElem(SString S)
{
	for (int i = 1; i <= S[0]; i++)
	{
		printf("%c", S[i]);
	}

	printf("\n");
}

int Index_BF(SString S, SString T)
{
	int i = 1, j = 1;
	while (i < S[0] && j <= T[0])
	{
		if (S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j >= T[0])
		return i - T[0];
	else
		return 0;
}

int main()
{
	char* chars01 = "abcdefg";
	char* chars02 = "cde";
	SString S, T;
	StrAssign(S, chars01);
	StrAssign(T, chars02);
	printf("字符串S为：");
	PrintElem(S);
	printf("字符串T为：");
	PrintElem(T);
	if (Index_BF(S, T))
		printf("匹配成功，T在S中的位置为：%d\n", Index_BF(S, T));
	else
		printf("匹配失败\n");

	return 0;
}
