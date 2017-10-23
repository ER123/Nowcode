#include <iostream>

using namespace std;

typedef struct BiNode
{
	int data;
	struct BiNode *lchild, *rchild;
}BiNode, *BiTree;

int searchBT(BiNode *T, int key)
{//递归搜索二叉排序树
	if (!T)
	{
		return false;
	}
	else if (key == T->data)
	{
		return 1;
	}
	else if (key < T->data)
	{
		return searchBT(T->lchild, key);
	}
	else
	{
		return searchBT(T->rchild, key);
	}

}

int insertSBT(BiNode* &T, int key)
{
	if (T == NULL)
	{
		T = new BiNode;
		T->data = key;
		T->lchild = T->rchild = NULL;
		return true;
	}
	if (key == T->data)
	{
		return -1;
	}
	else if (key < T->data)
	{//key小于结点值插入左侧
		insertSBT(T->lchild, key);
	}
	else
	{//key大于结点值插入右侧
		insertSBT(T->rchild, key);
	}
}

int createBT(BiNode* &T, int a[])
{
	T = NULL;
	for (int i = 0; i < 10; i++)
	{
		insertSBT(T, a[i]);
	}

	return true;
}

void delete_T(BiNode* &p)
{
	BiNode *q, *s;
	q = new BiNode;
	q->lchild = q->rchild = NULL;
	s = new BiNode;
	s->lchild = s->rchild = NULL;

	//1.如果左子树为空，将右子树直接接到原来的位置
	if (p->lchild == NULL)
	{
		q = p;
		p = p->rchild;
		delete q;
	}
	//2.如果右子树为空，将左子树直接接到原来的位置
	else if (p->rchild == NULL)
	{
		q = p;
		p = p->lchild;
		delete q;
	}
	//3.如果左右子树都不空，
	//(1)直接前驱结点接到删除位置，直接前驱的左子树接到前驱的前驱的右子树
	//(2)直接后继结点接到原来位置，直接后继的右子树接到后继的前驱的左子树
	else
	{
		/* 直接前驱的左子树接到前驱的前驱的右子树 */
		//q = p;
		//s = p->lchild;
		//while (s->rchild)
		//{
		//	q = s;
		//	s = s->rchild;
		//}
		//p->data = s->data;
		//if (q != p)
		//	q->rchild = s->lchild;
		//else
		//	q->lchild = s->lchild;

		/* 直接后继的右子树接到后继的前驱的左子树*/
		q = p;
		s = p->rchild;
		while (s->lchild)
		{
			q = s;
			s = s->lchild;
		}
		p->data = s->data;
		if (q != p)
			q->lchild = s->rchild;
		else
			q->rchild = s->rchild;

		delete s;
	}
}

int deleteBT(BiNode* &T, int key)
{
	if (!T)
	{
		return 0;
	}
	else
	{
		if (key == T->data)
			delete_T(T);
		else if (key < T->data)
			deleteBT(T->lchild, key);
		else
			deleteBT(T->rchild, key);
	}
}

void preOrderTravel(BiTree T)
{
	if (T)
	{
		cout << "key: "<<T->data <<"  ";
		preOrderTravel(T->lchild);
		preOrderTravel(T->rchild);
	}
}

void midOrderTravel(BiTree T)
{
	if (T)
	{
		midOrderTravel(T->lchild);
		cout << "key: " << T->data << "  ";
		midOrderTravel(T->rchild);
	}
}

int main()
{
	int a[10] = { 4, 6, 9, 3, 2, 10, 5, 8, 7,1 };
	BiTree T;
	createBT(T,a);

	cout << "先根遍历：" << endl;
	preOrderTravel(T);

	cout << "中根遍历：" << endl;
	midOrderTravel(T);

	int key;
	key = 5;
	if (searchBT(T, key))
		cout << "FIND!" << endl;
	else
		cout << "NOT FOUND!" << endl;

	deleteBT(T, 9);

	cout << "中根遍历：" << endl;
	midOrderTravel(T);

	return 0;
}
