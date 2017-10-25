#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> adjust(vector<int> v, int n)
{
	vector<int> vec;
	if (v.size() == 0)
		return vec;
	int j = n;
	for (int i = 0; i < v.size() - n; i++)
		vec.push_back(v[j++]);
	return vec;
}
//从前序和后续遍历重建二叉树
TreeNode* rebuild(vector<int> pre, vector<int> vin, int n)
{	
	if (n == 0)
		return NULL;

	int k = 0;
	while (pre[0] != vin[k])
		k++;

	TreeNode* p = new TreeNode(pre[0]);

	vector<int> v11;
	v11 = adjust(pre, 1);
	p->left = rebuild(v11, vin, k);

	vector<int> v22;
	v11 = adjust(pre, k + 1);
	v22 = adjust(vin, k + 1);
	p->right = rebuild(v11, v22, n - k - 1);

	return p;
}

TreeNode* reBuildBT(vector<int> pre, vector<int> vin)
{
	int n = vin.size();
	TreeNode * p = new TreeNode(pre[0]);
	p = rebuild(pre, vin, n);

	return p;
}

vector<int> adjust1(vector<int> v, int k)
{
	vector<int> v1;
	if (v.size() == 0)
		return v1;
	int j = k;
	for (int i = 0; i < v.size() - k; i++)
	{
		v1.push_back(v[j++]);
	}
	return v1;
}
//从中序和后序重建二叉树
TreeNode* rebuild0(vector<int> vin, vector<int> post, int n)
{
	if (n == 0)
		return NULL;

	int k = 0;
	while (vin[k] != post[n-1])
		k++;

	TreeNode* p = new TreeNode(post[n-1]);

	p->left = rebuild0(vin, post, k);

	vector<int> v11;
	vector<int> v22;
	v11 = adjust1(vin, k + 1);
	v22 = adjust1(post, k);
	p->right = rebuild0(v11, v22, n - k - 1);

	return p;
}

TreeNode *reBuildBT_M_P(vector<int> vin, vector<int> post)
{
	int n = vin.size();
	TreeNode * p = new TreeNode(post[n-1]);
	p = rebuild0(vin, post, n);

	return p;
}

void print_BT(TreeNode *p)
{
	if (p)
	{
		print_BT(p->left);
		print_BT(p->right);
		cout << p->val << " ";
	}
}

int main()
{
	vector<int> v1 = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> v2 = { 4, 7, 2, 1, 5, 3, 8, 6 };
	vector<int> v3 = { 7, 4, 2, 5, 8, 6, 3, 1 };

	//已知前序和中序遍历求原二叉树
	TreeNode * p = reBuildBT(v1, v2);
	cout << "后序遍历：" << endl;
	print_BT(p);
	cout << endl;

	//已知中序和后序遍历求原二叉树
	TreeNode * pp = reBuildBT_M_P(v2, v3);
	cout << "后序遍历：" << endl;
	print_BT(p);
	cout << endl;

	system("pause");
	return 0;
}
