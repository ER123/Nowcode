#include <iostream>

using namespace std;

typedef struct BiNode
{
	int data;
	struct BiNode *lchild, *rchild;
}BiNode, *BiTree;

int searchBT(BiNode *T, int key)
{
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
	{
		insertSBT(T->lchild, key);
	}
	else
	{
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

	return 0;
}
