#ifndef BITREE_H
#define BITREE_H

#include "Status.h"

/* ������Ԫ�����Ͷ��壬���������Ԫ������Ϊchar */
typedef char TElemType;

/* ��������㶨�� */
typedef struct BiTNode {
    TElemType data;             // ���Ԫ��
    struct BiTNode* lchild;     // ����ָ��
    struct BiTNode* rchild;     // �Һ���ָ��
} BiTNode;

/* ָ�����������ָ�� */
typedef BiTNode* BiTree;

/*
 * ��ʼ�� ����ն�������
 */
Status InitBiTree(BiTree* T);

// ���������С�������������
void CreateTree(BiTree* T);

// �������������
Status PreOrderTraverse(BiTree T);

// �������������
Status InOrderTraverse(BiTree T);

// �������������
Status PostOrderTraverse(BiTree T);

#endif
