#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV) 
{
	if (popV.empty() && pushV.empty())
		return true;

	stack<int> s;
	int i = 0;
	int j = 0;
	bool res;
	while (i < pushV.size())
	{
		s.push(pushV[i++]);
		while (!s.empty() && s.top() == popV[j])
		{
			s.pop();
			j++;
		}
	}
	return s.empty();


	//if (pushV.size() == 0)
	//	return false;
	//vector<int> s;
	//for (int i = 0, j = 0; i < pushV.size();)
	//{
	//	s.push_back(pushV[i++]);
	//	while (j < popV.size() && !s.empty() && s.back() == popV[j])
	//	{
	//		s.pop_back();
	//		j++;
	//	}
	//}
	//return s.empty();
}

int main()
{
	vector<int> pushV = { 1 ,2,3,4,5};
	//vector<int> popV = { 4, 5, 1, 2, 3 };
	vector<int> popV = { 1,2,3,4,5 };
	//vector<int> popV = { 4, 3, 5, 1, 2 };

	//vector<int> popV = { 4,1,2};

	if (IsPopOrder(pushV, popV))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	system("pause");

	return 0;
}
