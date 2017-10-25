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
	int j = n;
	for (int i = 0; i < v.size() - n; i++)
		vec.push_back(v[j++]);
	return vec;
}

TreeNode* rebuild(vector<int> v1, vector<int> v2, int n)
{
	if (n == 0)
		return NULL;
	
	int k = 0;
	while (v1[0] != v2[k])
		k++;
	
	TreeNode* p = new TreeNode(v1[0]);

	vector<int> v11;
	v11 = adjust(v1, 1);
	p->left = rebuild(v11, v2, k);
	
	vector<int> v22;
	v11 = adjust(v1, k + 1);
	v22 = adjust(v2, k + 1);
	p->right = rebuild(v11, v22, n - k - 1);
	
	return p;
}

int main()
{
	vector<int> v1 = { 1, 2, 3 };
	vector<int> v2 = { 2, 1, 3 };

	TreeNode * p = rebuild(v1, v2, 3);

	return 0;
}
