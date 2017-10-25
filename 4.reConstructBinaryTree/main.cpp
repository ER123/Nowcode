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

int main()
{
	vector<int> v1 = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> v2 = { 4, 7, 2, 1, 5, 3, 8, 6 };

	TreeNode * p = reBuildBT(v1, v2);

	system("pause");
	return 0;
}
