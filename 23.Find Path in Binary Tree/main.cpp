class Solution {
    vector<vector<int> > allPath;
	vector<int> path0;
    void FindAllPath(TreeNode *root, int expectNumber, int &sum)
	{
		sum += root->val;
		path0.push_back(root->val);

		bool isLeaf = root->left == NULL && root->right == NULL;
		if (sum == expectNumber && isLeaf)
		{
			allPath.push_back(path0);
		}

		if (root->left != NULL)
		{
			FindAllPath(root->left, expectNumber, sum);
		}
		if (root->right != NULL)
		{
			FindAllPath(root->right, expectNumber, sum);
		}

		sum -= root->val;
		path0.pop_back();
	}
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (root == NULL)
			return allPath;
        int sum=0;
        FindAllPath(root, expectNumber, sum);
        return allPath;
    }
};
