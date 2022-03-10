#ifndef STATUS_H
#define STATUS_H

// 函数结果状态码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

// 系统中已有此状态码定义，要防止冲突
#ifndef OVERFLOW
#define OVERFLOW -2  //堆栈上溢
#endif

// Status是函数的类型，其值是函数结果状态码
typedef int Status;

#endif
