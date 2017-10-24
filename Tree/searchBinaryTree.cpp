#include <iostream>
#include <stack>

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
		q = p;
		s = p->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		p->data = s->data;
		if (q != p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;

		///* 直接后继的右子树接到后继的前驱的左子树*/
		//q = p;
		//s = p->rchild;
		//while (s->lchild)
		//{
		//	q = s;
		//	s = s->lchild;
		//}
		//p->data = s->data;
		//if (q != p)
		//	q->lchild = s->rchild;
		//else
		//	q->rchild = s->rchild;

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
		cout << "key: " << T->data << "  ";
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

void posOrderTravel(BiTree T)
{
	if (T)
	{
		posOrderTravel(T->lchild);
		posOrderTravel(T->rchild);
		cout << "key: " << T->data << "  ";
	}
}

void visit(BiTree T)
{
	cout << "key: " << T->data << "  ";
}
//借助一个栈，每次访问一个结点之后，在左子树遍历下去之前利用栈记录该节点的右孩子结点地址
//以便在左子树回退时可以直接从栈订取得右子树的根节点，继续右子树的前序遍历
void perOrderTravel_iteration(BiTree T, stack<BiTree> s)
{
	while (T != NULL)
	{
		visit(T);
		if (T->rchild != NULL)
			s.push(T->rchild);
		if (T->lchild != NULL)
		{
			T = T->lchild;
		}
		else
		{
			if (s.empty() == false)
			{
				T = s.top();
				s.pop();
			}
			else
				return;
		}
	}
}
//如果某结点的右子树遍历完成或者右子树为空，说明以这个结点为根的二叉树遍历完，
//此时从栈中推出更上层的结点并访问它，再向它的右子树遍历下去
void midOrderTravel_iteration(BiTree T, stack<BiTree> s)
{
	do{
		while (T != NULL)
		{
			s.push(T);
			T = T->lchild;
		}
		if (!s.empty())
		{
			T = s.top();
			s.pop();
			visit(T);
			T = T->rchild;
		}
	} while (T != NULL || !s.empty());
}
enum Tag { L, R };
struct stkNode
{
	BiTree p;
	Tag tag;
};
//给每个节点附加一个标记(left,right)。如果该节点的左子树已被访问过则置标记为left；
//若右子树被访问过，则置标记为right。显然，只有当节点的标记位是right时，才可访问该节点；
//否则，必须先进入它的右子树
void posOrderTravel_interation(BiTree T)
{
	stack<stkNode> s;
	stkNode w;
	BiTree root = T;
	do
	{
		while (root != NULL)
		{
			w.p = root;
			w.tag = L;
			s.push(w);
			root = root->lchild;
		}
		w = s.top();
		s.pop();
		if (w.tag == R)
		{	
			visit(w.p);
			root = NULL;
		}
		else
		{
			w.tag = R;
			s.push(w);
			root = w.p;
			root = root->rchild;
		}

	} while (root!=NULL || !s.empty());
}

int main()
{
	int a[10] = { 4, 6, 9, 3, 2, 10, 5, 8, 7, 1 };
	BiTree T;
	createBT(T, a);

	cout << "递归遍历" << endl;

	cout << "先序遍历：" << endl;
	preOrderTravel(T);
	cout << endl;
	cout << "中序遍历：" << endl;
	midOrderTravel(T);
	cout << endl;
	cout << "后序遍历：" << endl;
	posOrderTravel(T);
	cout << endl;

	int key;
	key = 5;
	cout << "寻找结点5结果： ";
	if (searchBT(T, key))
		cout << "FIND!" << endl;
	else
		cout << "NOT FOUND!" << endl;
	cout << endl;
	
	deleteBT(T, 9);
	cout << "删除结点9后" << endl;
	cout << "前序遍历：" << endl;
	preOrderTravel(T);
	cout << endl;
	cout << "中序遍历：" << endl;
	midOrderTravel(T);
	cout << endl;
	cout << "后序遍历：" << endl;
	posOrderTravel(T);
	cout << endl << endl;

	cout << "非递归遍历：" << endl;
	stack<BiTree> s1;
	cout << "先序遍历：" << endl;
	perOrderTravel_iteration(T, s1);
	cout << endl;
	cout << "中序遍历：" << endl;
	midOrderTravel_iteration(T, s1);
	cout << endl;
	cout << "后序遍历：" << endl;
	posOrderTravel_interation(T);

	return 0;
}
