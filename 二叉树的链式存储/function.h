#pragma once
#include <stdio.h>
#include<stdlib.h>

/*
* 二叉树的链式存储
*/
typedef char BiElemType;
//树节点
typedef struct BiLNode {
	BiElemType c;
	struct BiLNode* lchild;
	struct BiLNode* rchild;
}BiLNode, * BiTree;
typedef struct tag {
	BiTree p;
	struct  tag* next;
}tag_t, * ptag_t;//辅助队列

#define MaxSize 50
typedef BiTree ElemType;
typedef struct LNode {
	ElemType data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack& s);
bool IsEmpty(SqStack S);
bool Push(SqStack& s, ElemType e);
bool Pop(SqStack& s, ElemType& e);

/*
* 队列
*/
typedef BiTree ElemType;
typedef struct LNodea {
	ElemType data[MaxSize];
	int rear, front;
}SqQueue;
void InitQueue(SqQueue& Q);
bool EnQueue(SqQueue& Q, ElemType e);
bool DeQueue(SqQueue& Q, ElemType& e);
bool IsEmpty(SqQueue Q);