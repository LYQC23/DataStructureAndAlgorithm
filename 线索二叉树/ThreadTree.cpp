#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElemType;
typedef struct ThreadNode {
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;
}ThreadNode, * ThreadTree;
//�ֹ������������ܼ�5�����
void BulidThreadTree(ThreadTree& T)
{
	ThreadTree arr[5];
	int i;
	for (i = 0; i < 5; i++)
	{
		arr[i] = (ThreadTree)malloc(sizeof(ThreadNode));
		memset(arr[i], 0, sizeof(ThreadNode));
		arr[i]->data = 'A' + i;
	}
	arr[0]->lchild = arr[1];
	arr[0]->rchild = arr[2];
	arr[1]->rchild = arr[3];
	arr[2]->lchild = arr[4];
	T = arr[0];
}

void InThread(ThreadTree& p, ThreadTree& pre)
{
	if (p != NULL) {
		InThread(p->lchild, pre);//�ݹ�����������
		if (p->lchild == NULL) {//���ΪNULL,��д��ǰ����ǰ��
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL) {
			//pre�ڵ��Һ���ΪNULL��������ָ���̽ڵ㣬����̽��պþ���p
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
		InThread(p->rchild, pre);
	}
}
void CreateInThread(ThreadTree T)
{
	ThreadTree pre = NULL;//ʹ�ø���ָ��pre
	if (T != NULL) {
		InThread(T, pre);
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}
//���������µĵ�һ�����
ThreadNode* Firstnode(ThreadNode* p)
{
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}
//p�����������µĺ�̽��

int main()
{
	ThreadTree T;
	ThreadTree p;
	BulidThreadTree(T);
	CreateInThread(T);//��������������
	p = Firstnode(T);
	printf("�����½��ֵΪ %c\n", p->data);
	system("pause");
}