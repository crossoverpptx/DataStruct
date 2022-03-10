#ifndef LINKSTACK_H
#define LINKSTACK_H

#include "Status.h"

// 元素类型定义
typedef int SElemType;

// 链栈的定义
typedef struct StackNode {
	SElemType data;
	struct StackNode* next;
}StackNode, *LinkStack;

// 链栈的初始化
Status InitStack(LinkStack& S);
// 判断链栈是否为空
Status StackEmpty(LinkStack S);
// 链栈的入栈
Status PushStack(LinkStack& S, SElemType e);
// 链栈的出栈
Status PopStack(LinkStack& S, SElemType& e);
// 取栈顶元素
SElemType GetTop(LinkStack S);

#endif
