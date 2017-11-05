#include <iostream>
#include <set>
#include <vector>

using namespace std;

//方法一：用multiset从大到小保存前k的数，依次比较input与multiset的元素大小，multiset利用红黑树实现，可以实现在logn的时间内插入调整
struct cmp
{
	bool operator()(const int &a, const int &b)
	{
		return a > b;
	}
};

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
{
	vector<int> res;
	multiset<int, cmp> miset;
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
//方法二：使用全排列，找到最小的k个数
vector<int> GetLeastNumbers_Solution1(vector<int> input, int k)
{
	vector<int> res;
	if (input.size()<=0 || input.size() < k)
		return res;
	sort(input.begin(), input.end());

	for (int i = 0; i < k;i++)
	{
		res.push_back(input[i]);
	}
	return res;
}

//方法三：根据快排思想，将input分为两部分，前一部分元素正好为k个时结束；
int Partition(vector<int> &input, int n, int start, int end)
{
	int low = start;
	int high = end;
	int temp = input[low];
	while (low<high)
	{
		while (input[high] > temp && low <high)
		{
			high--;
		}
		input[low] = input[high];
		while (input[low] <= temp && low <high)
		{
			low++;
		}
		input[high] = input[low];
	}
	input[low] = temp;
	return low;
}

vector<int> GetLeastNumbers_Solution2(vector<int> input, int k)
{
	vector<int> res;
	if (input.size() <= 0 || input.size() < k)
		return res;
	int n = input.size();
	int start = 0;
	int end = n - 1;
	int index = Partition(input, n, start, end);
	while (index != k-1)
	{
		if (index > k - 1)
		{
			end = index - 1;
			index = Partition(input, n, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(input, n, start, end);
		}
	}
	for (int i = 0; i < k;i++)
	{
		res.push_back(input[i]);
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
