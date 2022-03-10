#ifndef SQSTACK_H
#define SQSTACK_H

#include "Status.h"

// 宏定义
#define MAXSIZE 100

// 元素类型定义
typedef int SElemType;

// 顺序栈的定义
typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

// 顺序栈的初始化
Status InitStack(SqStack& S);
// 判断顺序栈是否为空
Status StackEmpty(SqStack S);
// 求顺序栈的长度
int StackLength(SqStack S);
// 清空顺序栈
Status ClearStack(SqStack& S);
// 销毁顺序栈
Status DestroyStack(SqStack& S);
// 顺序栈的入栈
Status PushStack(SqStack& S, SElemType e);
// 顺序栈的出栈
Status PopStack(SqStack& S, SElemType& e);

#endif
