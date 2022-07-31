#include <stdio.h>
#include <stdlib.h>

//�����������Ĵ�����������������ң�ɾ��
typedef int KeyType;
typedef struct BSTNode {
	KeyType key;
	struct BSTNode* lchild, * rchild;
}BSTNode, * BiTree;
//54,20,66,40,28,79,58
int BST_Insert(BiTree& T, KeyType k)
{
	if (NULL == T)
	{	//Ϊ�½ڵ�����ռ䣬��һ�������Ϊ����
		T = (BiTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return 1;//�������ɹ�
	}
	else if (k == T->key)
		return 0;//������ͬԪ�أ��Ͳ�����
	else if (k < T->key)//���Ҫ����Ľ�㣬С�ڵ�ǰ���
		return BST_Insert(T->lchild, k);//�������ý��������Ӻ�ԭ���ĸ��׻��������
	else
		return BST_Insert(T->rchild, k);
}
//��������������
void Creat_BST(BiTree& T, KeyType str[], int n)
{
	T = NULL;
	int i = 0;
	while (i < n)
	{
		BST_Insert(T, str[i]);//��ĳһ����������������
		i++;
	}
}
//�ݹ��㷨�򵥣���ִ��Ч�ʽϵͣ��ݹ�ʵ��������ұ�д
BSTNode* BST_Search(BiTree T, KeyType key, BiTree& p)
{
	p = NULL;//�洢Ҫ�ҵĽ��ĸ���
	while (T != NULL && key != T->key)
	{
		p = T;
		if (key < T->key) T = T->lchild;//�ȵ�ǰ�ڵ�С���������
		else T = T->rchild;//�ȵ�ǰ�ڵ���ұ�ȥ
	}
	return T;
}

void DeleteNode(BiTree& root, KeyType x) {
	if (root == NULL) {
		return;
	}
	if (root->key > x) {
		DeleteNode(root->lchild, x);
	}
	else if (root->key < x) {
		DeleteNode(root->rchild, x);
	}
	else { //���ҵ���ɾ���ڵ�
		if (root->lchild == NULL) { //������Ϊ�գ�������ֱ�Ӷ���ȥ
			BiTree tempNode = root;//����ʱ�Ĵ��ŵ�Ŀ����һ��Ҫfree
			root = root->rchild;
			free(tempNode);
		}
		else if (root->rchild == NULL) { //������Ϊ�գ�������ֱ�Ӷ���ȥ
			BiTree tempNode = root;//��ʱָ��
			root = root->lchild;
			free(tempNode);
		}
		else {  //������������Ϊ��
		   //һ���ɾ����������������������� �� ����������С���� ����Ҫɾ���Ľڵ�(������ò����������������������)
			BiTree tempNode = root->lchild;
			if (tempNode->rchild != NULL) {
				tempNode = tempNode->rchild;
			}
			root->key = tempNode->key;
			DeleteNode(root->lchild, tempNode->key);
		}
	}
}

void InOrder(BiTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		printf("%3d", T->key);
		InOrder(T->rchild);
	}
}


int main()
{
	BiTree T = NULL;//����
	BiTree parent;//�洢���׽��ĵ�ֵַ
	BiTree search;
	KeyType str[7] = { 54,20,66,40,28,79,58 };//��Ҫ���������������Ԫ��ֵ
	Creat_BST(T, str, 7);
	InOrder(T);
	printf("\n");
	search = BST_Search(T, 40, parent);
	if (search)
	{
		printf("�ҵ���Ӧ��㣬ֵ=%d\n", search->key);
	}
	else {
		printf("δ�ҵ���Ӧ���\n");//û�ҵ�search���ص���NULL
	}
	DeleteNode(T, 54);//ɾ��ĳ�����
	InOrder(T);
	printf("\n");
	system("pause");
}