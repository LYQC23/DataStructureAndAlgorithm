#pragma once
#include <stdio.h>
#include<stdlib.h>

/*
* ����������ʽ�洢
*/
typedef char BiElemType;
//���ڵ�
typedef struct BiLNode {
	BiElemType c;
	struct BiLNode* lchild;
	struct BiLNode* rchild;
}BiLNode, * BiTree;
typedef struct tag {
	BiTree p;
	struct  tag* next;
}tag_t, * ptag_t;//��������

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
* ����
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