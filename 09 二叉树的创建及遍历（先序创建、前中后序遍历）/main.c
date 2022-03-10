# include <stdio.h>
#include "BiTree.h"

int main()
{
    BiTree T;

    printf("初始化空二叉树");
    InitBiTree(&T);
    printf("\n按先序序列创建二叉树：");
    CreateTree(&T);
    printf("先序遍历二叉树：");
    PreOrderTraverse(T);
    printf("\n中序遍历二叉树：");
    InOrderTraverse(T);
    printf("\n后序遍历二叉树：");
    PostOrderTraverse(T);
    printf("\n");
    return 0;
}
