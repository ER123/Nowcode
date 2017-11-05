#include <iostream>
#include <set>
#include <vector>

using namespace std;
struct greater
{
	bool operator()(const int &a, const int &b)
	{
		return a > b;
	}
};

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
{
	vector<int> res;
	multiset<int, greater> miset;
	if (input.empty())
	{
		return res;
	}
	if (k > input.size())
		return input;

	vector<int>::iterator iter = input.begin();
	while (iter != input.end())
	{
		if (miset.size()<k)
		{
			miset.insert(*iter);
		}
		else
		{
			multiset<int>::iterator setIter = miset.begin();
			if (*iter <*(miset.begin()))
			{
				miset.erase(setIter);
				miset.insert(*iter);
			}
		}
		iter++;
	}
	multiset<int>::iterator iter_set = miset.begin();
	for (; iter_set!= miset.end();iter_set++)
	{
		res.push_back(*iter_set);
	}
	return res;
}

int main()
{
	vector<int> input = { 2, 3, 4,1, 5, 6, 0, 6, 3, 2, 5, 7, 8, 9, 10 };
	int k = 4;
	vector<int> res = GetLeastNumbers_Solution(input, k);

	system("pause");
	return 0;
}
