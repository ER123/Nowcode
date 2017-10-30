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
	for (; i < len-1;i++)
	{
		if (seq[i] > seq[len-1])
			break;
	}
	int j = i;
	for (; j < len-1; j++)
	{
		if (seq[j]<seq[len-1])
			return false;
	}

	bool left = true;
	if (i > 0)
		left = isSBT(seq, i);
	bool right = true;
	if (i < len - 1)
	{
		seq = adjust(seq, i);
		right = isSBT(seq, len - i - 1);
	}

	return (left&&right);
}
