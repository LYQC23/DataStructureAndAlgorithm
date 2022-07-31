#include"function.h"



void InitStack(SqStack& s)
{
	s.top = -1;
}

bool IsEmpty(SqStack S)
{
	if (S.top == -1)
	{
		return true;
	}
	return false;
}

bool Push(SqStack& s, ElemType e)
{
	if (s.top == MaxSize - 1)
		return false;
	s.top++;
	s.data[s.top] = e;
	return true;
}

bool Pop(SqStack& s, ElemType& e)
{
	if (IsEmpty(s))
		return false;
	e = s.data[s.top];
	s.top--;
	return true;
}