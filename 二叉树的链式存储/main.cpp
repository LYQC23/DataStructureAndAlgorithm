#include "function.h"

//�ݹ�ʵ��
//abdhiejcfg  ǰ�������ǰ���������������ȱ���
void preOrder(BiTree p)
{
	if (p != NULL)
	{
		putchar(p->c);//�ȼ���visit����
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}
//�������  hdibjeafcg
void InOrder(BiTree p)
{
	if (p != NULL)
	{
		InOrder(p->lchild);
		putchar(p->c);
		InOrder(p->rchild);
	}
}
//hidjebfgca  �������
void PostOrder(BiTree p)
{
	if (p != NULL)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		putchar(p->c);
	}
}
//��������ǵݹ飬�ǵݹ�ִ��Ч�ʸ��ߣ����ĸ��ʺܵ�
void InOrder2(BiTree T)
{
	SqStack S;
	InitStack(S); BiTree p = T;
	while (p || !IsEmpty(S))//�߼���||
	{
		if (p)
		{//��һ����㲻Ϊ�գ�ѹջ����ȡ����
			Push(S, p);
			p = p->lchild;
		}
		else {//����ջ��Ԫ�ز���ӡ����ȡ��ӡԪ�ص��ҽ��
			Pop(S, p); putchar(p->c);
			p = p->rchild;
		}
	}
}
//��α���,���������������ȱ���
void LevelOrder(BiTree T)
{
	SqQueue Q;//��������
	InitQueue(Q);//��ʼ������
	BiTree p;
	EnQueue(Q, T);//�������
	while (!IsEmpty(Q))
	{
		DeQueue(Q, p);//���ӵ�ǰ��㲢��ӡ
		putchar(p->c);
		if (p->lchild != NULL) //�������
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)  //����Һ���
			EnQueue(Q, p->rchild);
	}
}

//�������Ľ�������ν�������ǰ�����򡢺������������ǵݹ��������α���
int main()
{
	BiTree pnew;
	int i, j, pos;
	char c;
	BiTree tree = NULL;//����
	ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;//phead���Ƕ���ͷ��ptail���Ƕ���β
	//abcdefghij
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')
		{
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiLNode));//calloc����ռ䲢�Կռ���г�ʼ������ֵΪ0
		pnew->c = c;//���ݷŽ�ȥ
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));//�����н������ռ�
		listpnew->p = pnew;
		if (NULL == tree)
		{
			tree = pnew;//���ĸ�
			phead = listpnew;//����ͷ
			ptail = listpnew;//����β
			pcur = listpnew;
			continue;
		}
		else {
			ptail->next= listpnew;//�½���������ͨ��β�巨
			ptail = listpnew;//ptailָ�����β��
		}//pcurʼ��ָ��Ҫ����Ľ���λ��
		if (NULL == pcur->p->lchild)//��ΰ��½�������
		{
			pcur->p->lchild = pnew;//���½��ŵ�Ҫ����������
		}
		else if (NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;//���½��ŵ�Ҫ��������ұ�
			pcur = pcur->next;//���Ҷ����˽���pcurָ����е���һ��
		}
	}
	printf("--------ǰ�����----------\n");//Ҳ������������ȴ�ӡ��ǰ��㣬��ӡ���ӣ���ӡ�Һ���
	preOrder(tree);
	printf("\n--------�������------------\n");//�ȴ�ӡ���ӣ���ӡ���ף���ӡ�Һ���
	InOrder(tree);
	printf("\n--------�������------------\n");//�ȴ�ӡ���ӣ���ӡ�Һ��ӣ�����ӡ����
	PostOrder(tree);
	printf("\n--------��������ǵݹ�------\n");//��Ҫ�Ե�
	InOrder2(tree);
	printf("\n--------��α���-----------\n");
	LevelOrder(tree);
	printf("\n");
	system("pause");
}