#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

/*
 * 初始化 构造空二叉树。
 */
Status InitBiTree(BiTree* T) {
    if (T == NULL) {
        return ERROR;
    }

    *T = NULL;

    return OK;
}

// 【先序序列】创建二叉树。
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
        // 生成根结点
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!(*T)) 
        {
            exit(OVERFLOW);
        }
        (*T)->data = ch;
        CreateTree(&((*T)->lchild)); // 创建左子树
        CreateTree(&((*T)->rchild)); // 创建右子树
    }
}

// 先序遍历二叉树
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

// 中序遍历二叉树
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

// 后序遍历二叉树
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
