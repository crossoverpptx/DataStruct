#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

/*
 * ��ʼ�� ����ն�������
 */
Status InitBiTree(BiTree* T) {
    if (T == NULL) {
        return ERROR;
    }

    *T = NULL;

    return OK;
}

// ���������С�������������
void CreateTree(BiTree* T)
{
    char ch;
    scanf_s("%c", &ch);

    if (ch == '^')
    {
        *T = NULL;
    }
    else 
    {
        // ���ɸ����
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!(*T)) 
        {
            exit(OVERFLOW);
        }
        (*T)->data = ch;
        CreateTree(&((*T)->lchild)); // ����������
        CreateTree(&((*T)->rchild)); // ����������
    }
}

// �������������
Status PreOrderTraverse(BiTree T) 
{
    if (T == NULL) 
    {
        return OK;
    }
    else 
    {
        printf("%c", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

// �������������
Status InOrderTraverse(BiTree T) 
{
    if (T == NULL) 
    {
        return OK;
    }
    else 
    {
        InOrderTraverse(T->lchild);
        printf("%c", T->data);
        InOrderTraverse(T->rchild);
    }
}

// �������������
Status PostOrderTraverse(BiTree T) 
{
    if (T == NULL) 
    {
        return OK;
    }
    else 
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%c", T->data);
    }
}
