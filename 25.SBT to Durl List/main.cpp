#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

int insertSBT(TreeNode* &T, int key)
{
	if (T == NULL)
	{
		T = new TreeNode(NULL);
		T->val = key;
		T->left = T->right = NULL;
		return true;
	}
	if (key == T->val)
	{
		return -1;
	}
	else if (key < T->val)
	{
		insertSBT(T->left, key);
	}
	else
	{
		insertSBT(T->right, key);
	}
}

int createBT(TreeNode* &T, int a[])
{
	T = NULL;
	for (int i = 0; i < 10; i++)
	{
		insertSBT(T, a[i]);
	}

	return true;
}

void convertTO(TreeNode *pNode, TreeNode **pLastNode)
{
	if (pNode == NULL)
		return;

	TreeNode *pCur = pNode;
	if (pCur->left != NULL)
		convertTO(pCur->left, pLastNode);
	
	pCur->left = *pLastNode;
	if (*pLastNode != NULL)
		(*pLastNode)->right = pCur;

	*pLastNode = pCur;
	if (pCur->right != NULL)
		convertTO(pCur->right, pLastNode);

}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	TreeNode *pLast = NULL;
	convertTO(pRootOfTree, &pLast);

	TreeNode *pHead = pLast;
	while (pHead != NULL && pHead->left != NULL)
		pHead = pHead->left;

	return pHead;
}

int main()
{
	int a[] = { 4, 6, 9, 3, 2, 10, 5, 8, 7, 1 };
	TreeNode *root;
	createBT(root, a);

	TreeNode *res = Convert(root);

	return 0;
}
