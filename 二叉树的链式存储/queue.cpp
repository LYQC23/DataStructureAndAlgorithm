#include"function.h"
/*
* ╤сап
*/

void InitQueue(SqQueue& Q)
{
	Q.rear = 0;
	Q.front = 0;
}
bool EnQueue(SqQueue& Q, ElemType e)
{
	if ((Q.rear + 1) % MaxSize == Q.front)
		return false;
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}
bool DeQueue(SqQueue& Q, ElemType& e)
{
	if (Q.rear == Q.front)
		return false;
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}
bool IsEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	return false;
}
