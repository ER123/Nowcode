#include <iostream>
#include <stack>

using namespace std;

stack<int> s1;
stack<int> s2;

void push_s(int node)
{
	s1.push(node);
}

int pop_s()
{
	int res;
	if (!s2.empty())
	{
		res = s2.top();
		s2.pop();
		return res;
	}
	else
	{
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		if (!s2.empty())
		{
			res = s2.top();
			s2.pop();
			return res;
		}
	}
	return NULL;
}

int main()
{
	for (int i = 0; i < 5; i++)
		push_s(i);

	for (int i = 0; i < 5; i++)
		cout << pop_s() << " ";
	cout << endl;
	
	return 0;
}
