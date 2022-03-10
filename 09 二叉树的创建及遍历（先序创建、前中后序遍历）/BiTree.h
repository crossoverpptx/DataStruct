#ifndef BITREE_H
#define BITREE_H

#include "Status.h"

/* 二叉树元素类型定义，这里假设其元素类型为char */
typedef char TElemType;

/* 二叉树结点定义 */
typedef struct BiTNode {
    TElemType data;             // 结点元素
    struct BiTNode* lchild;     // 左孩子指针
    struct BiTNode* rchild;     // 右孩子指针
} BiTNode;

/* 指向二叉树结点的指针 */
typedef BiTNode* BiTree;

/*
 * 初始化 构造空二叉树。
 */
Status InitBiTree(BiTree* T);

// 【先序序列】创建二叉树。
void CreateTree(BiTree* T);

// 先序遍历二叉树
Status PreOrderTraverse(BiTree T);

// 中序遍历二叉树
Status InOrderTraverse(BiTree T);

// 后序遍历二叉树
Status PostOrderTraverse(BiTree T);

#endif
