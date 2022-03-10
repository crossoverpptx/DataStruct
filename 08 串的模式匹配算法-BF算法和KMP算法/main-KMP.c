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


void getNextValue(SString T, int size_T, int* nextVal)          //求模式串的next数组并存入nextVal中
{
	int i, j;
	i = 1;                                         //后缀游标
	j = 0;                                         //前缀游标
	nextVal[1] = 0;

	while (i < size_T)
	{
		if (j == 0 || T[i] == T[j])                  //T[i]表示后缀的单个字符，T[j]表示前缀的单个字符
		{
			++i;
			++j;

			nextVal[i] = j;
		}
		else
		{
			j = nextVal[j];             //前缀与后缀不同，游标j回溯到nextVal[j]的位置，重新与失配的i位置的字符对比
		}
	}

}

int Index_KMP(SString S, SString T)
{
	int i = 1, j = 1;
	int* next = (int*)malloc(sizeof(int)*T[0]);
	next[0] = T[0];
	getNextValue(T, T[0], next);

	while (i < S[0] && j <= T[0])
	{
		if (S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}

	if (j >= T[0])
		return i - T[0];
	else
		return 0;
}

int main()
{
	const char* chars01 = "ababaaababcaa";
	const char* chars02 = "ababc";
	SString S, T;
	StrAssign(S, chars01);
	StrAssign(T, chars02);
	printf("字符串S为：");
	PrintElem(S);
	printf("字符串T为：");
	PrintElem(T);
	if (Index_KMP(S, T))
		printf("匹配成功，T在S中的位置为：%d\n", Index_KMP(S, T));
	else
		printf("匹配失败\n");

	return 0;
}
