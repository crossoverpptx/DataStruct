# include <stdio.h>
#include "BiTree.h"

int main()
{
    BiTree T;

    printf("��ʼ���ն�����");
    InitBiTree(&T);
    printf("\n���������д�����������");
    CreateTree(&T);
    printf("���������������");
    PreOrderTraverse(T);
    printf("\n���������������");
    InOrderTraverse(T);
    printf("\n���������������");
    PostOrderTraverse(T);
    printf("\n");
    return 0;
}
