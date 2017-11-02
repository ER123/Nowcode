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
/*
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
}*/
void convertTO(TreeNode *pNode, TreeNode *&pPre)
{
	if (pNode == NULL)
		return;
	
	convertTO(pNode->left, pPre);
	
	pNode->left = pPre;
	if (pPre)
		pPre->right = pNode;
	pPre = pNode;

	convertTO(pNode->right, pPre);
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	if (pRootOfTree == NULL)
		return NULL;

	TreeNode *pPre = NULL;
	convertTO(pRootOfTree, pPre);

	TreeNode *pHead = pPre;
	while (pHead->left)
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


//方法一：非递归版
//解题思路：
//1.核心是中序遍历的非递归算法。
//2.修改当前遍历节点与前一遍历节点的指针指向。
//import java.util.Stack;
//public TreeNode ConvertBSTToBiList(TreeNode root) {
//	if (root == null)
//		return null;
//	Stack<TreeNode> stack = new Stack<TreeNode>();
//	TreeNode p = root;
//	TreeNode pre = null;// 用于保存中序遍历序列的上一节点
//	boolean isFirst = true;
//	while (p != null || !stack.isEmpty()){
//		while (p != null){
//			stack.push(p);
//			p = p.left;
//		}
//		p = stack.pop();
//		if (isFirst){
//			root = p;// 将中序遍历序列中的第一个节点记为root
//			pre = root;
//			isFirst = false;
//		}
//		else{
//			pre.right = p;
//			p.left = pre;
//			pre = p;
//		}
//		p = p.right;
//	}
//	return root;
//}
//方法二：递归版
//解题思路：
//1.将左子树构造成双链表，并返回链表头节点。
//2.定位至左子树双链表最后一个节点。
//3.如果左子树链表不为空的话，将当前root追加到左子树链表。
//4.将右子树构造成双链表，并返回链表头节点。
//5.如果右子树链表不为空的话，将该链表追加到root节点之后。
//6.根据左子树链表是否为空确定返回的节点。
//public TreeNode Convert(TreeNode root) {
//	if (root == null)
//		return null;
//	if (root.left == null&&root.right == null)
//		return root;
//	// 1.将左子树构造成双链表，并返回链表头节点
//	TreeNode left = Convert(root.left);
//	TreeNode p = left;
//	// 2.定位至左子树双链表最后一个节点
//	while (p != null&&p.right != null){
//		p = p.right;
//	}
//	// 3.如果左子树链表不为空的话，将当前root追加到左子树链表
//	if (left != null){
//		p.right = root;
//		root.left = p;
//	}
//	// 4.将右子树构造成双链表，并返回链表头节点
//	TreeNode right = Convert(root.right);
//	// 5.如果右子树链表不为空的话，将该链表追加到root节点之后
//	if (right != null){
//		right.left = root;
//		root.right = right;
//	}
//	return left != null ? left : root;
//}
//方法三：改进递归版
//解题思路：
//思路与方法二中的递归版一致，仅对第2点中的定位作了修改，新增一个全局变量记录左子树的最后一个节点。
//// 记录子树链表的最后一个节点，终结点只可能为只含左子树的非叶节点与叶节点
//protected TreeNode leftLast = null;
//public TreeNode Convert(TreeNode root) {
//	if (root == null)
//		return null;
//	if (root.left == null&&root.right == null){
//		leftLast = root;// 最后的一个节点可能为最右侧的叶节点
//		return root;
//	}
//	// 1.将左子树构造成双链表，并返回链表头节点
//	TreeNode left = Convert(root.left);
//	// 3.如果左子树链表不为空的话，将当前root追加到左子树链表
//	if (left != null){
//		leftLast.right = root;
//		root.left = leftLast;
//	}
//	leftLast = root;// 当根节点只含左子树时，则该根节点为最后一个节点
//	// 4.将右子树构造成双链表，并返回链表头节点
//	TreeNode right = Convert(root.right);
//	// 5.如果右子树链表不为空的话，将该链表追加到root节点之后
//	if (right != null){
//		right.left = root;
//		root.right = right;
//	}
//	return left != null ? left : root;
//}
