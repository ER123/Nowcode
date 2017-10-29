#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV) 
{
	if (popV.empty() && pushV.empty())
		return true;

	stack<int> s0;
	int i = 1;
	int j = 0;
	s0.push(pushV[0]);

	while(i<pushV.size())
	{
		while (s0.top() != popV[j])
		{
			s0.push(pushV[i++]);
		}
		if (i == pushV.size())
			return false;

		if (s0.top() == popV[j++])
			s0.pop();
	}

	return true;
}

int main()
{
	vector<int> pushV = { 1, 2, 3, 4, 5 };
	vector<int> popV = { 4, 5, 1, 2, 3 };

	if (IsPopOrder(pushV, popV))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	system("pause");

	return 0;
}
