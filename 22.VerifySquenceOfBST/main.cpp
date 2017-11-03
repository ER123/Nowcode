vector<int> adjust(vector<int> &seq, int start)
{
	vector<int> v;
	for (int i = start; i < seq.size(); i++)
		v.push_back(seq[i]);
	return v;
}

bool isSBT(vector<int> seq, int len)
{
	if (seq.empty() || len <= 0)
		return false;
	int i = 0;
	for (; i < len-1;i++)//找到最后一个小于根节点的
	{
		if (seq[i] > seq[len-1])
			break;
	}
	int j = i;
	for (; j < len-1; j++)//最后一个小于根节点后面的结点都不小于根节点，否则就不是二叉搜索树
	{
		if (seq[j]<seq[len-1])
			return false;
	}

	bool left = true;
	if (i > 0)
		left = isSBT(seq, i);//验证左半部分
	bool right = true;
	if (i < len - 1)
	{
		seq = adjust(seq, i);
		right = isSBT(seq, len - i - 1);//验证右半部分
	}

	return (left&&right);
}
