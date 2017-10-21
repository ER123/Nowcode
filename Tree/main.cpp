#include <iostream>
#include <time.h>
typedef char Element;

using namespace std;

typedef struct BiTNode
{
	Element data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef struct ST
{
	long a; int b; char c[2];
}NEW;



void initTree(BiTree *tree)
{
	char c;
	scanf("%c", &c);
	if (c == ' ')
	{
		*tree = NULL;
	}
	else
	{
		*tree = (BiTNode *)malloc(sizeof(BiTNode));
		(*tree)->data = c;
		initTree(&(*tree)->lchild);
		initTree(&(*tree)->rchild);
	}
}

void vist(char c, int level)
{
	cout << c << " in level " << level << endl;
}

void first_travese(BiTree tree, int level)
{
	if (tree != NULL)
	{
		vist(tree->data, level);
		first_travese(tree->lchild, level + 1);
		first_travese(tree->rchild, level + 1);
	}
}

void mid_travese(BiTree tree, int level)
{
	if (tree != NULL)
	{
		first_travese(tree->lchild, level + 1);
		vist(tree->data, level);
		first_travese(tree->rchild, level + 1);
	}
}

void last_traves(BiTree tree, int level)
{
	if (tree != NULL)
	{
		first_travese(tree->lchild, level + 1);
		first_travese(tree->rchild, level + 1);
		vist(tree->data, level);
	}
}

int main()
{
	BiTree tree = NULL;
	int level = 0;

	initTree(&tree);

	cout << "前序遍历：" << endl;
	first_travese(tree, level);
	cout << "中序遍历：" << endl;
	mid_travese(tree, level);
	cout << "后序遍历：" << endl;
	last_traves(tree, level); 

	return 0;
}
