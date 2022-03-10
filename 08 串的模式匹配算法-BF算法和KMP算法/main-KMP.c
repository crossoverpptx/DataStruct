#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 255

typedef unsigned char SString[MAXLEN + 1];       // 0�ŵ�Ԫ��Ŵ��ĳ���

/*
 * ��ʼ��������һ��ֵΪchars�Ĵ�T��
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

// ���Ժ�������ӡ�ַ���
void PrintElem(SString S)
{
	for (int i = 1; i <= S[0]; i++)
	{
		printf("%c", S[i]);
	}

	printf("\n");
}


void getNextValue(SString T, int size_T, int* nextVal)          //��ģʽ����next���鲢����nextVal��
{
	int i, j;
	i = 1;                                         //��׺�α�
	j = 0;                                         //ǰ׺�α�
	nextVal[1] = 0;

	while (i < size_T)
	{
		if (j == 0 || T[i] == T[j])                  //T[i]��ʾ��׺�ĵ����ַ���T[j]��ʾǰ׺�ĵ����ַ�
		{
			++i;
			++j;

			nextVal[i] = j;
		}
		else
		{
			j = nextVal[j];             //ǰ׺���׺��ͬ���α�j���ݵ�nextVal[j]��λ�ã�������ʧ���iλ�õ��ַ��Ա�
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
	printf("�ַ���SΪ��");
	PrintElem(S);
	printf("�ַ���TΪ��");
	PrintElem(T);
	if (Index_KMP(S, T))
		printf("ƥ��ɹ���T��S�е�λ��Ϊ��%d\n", Index_KMP(S, T));
	else
		printf("ƥ��ʧ��\n");

	return 0;
}
