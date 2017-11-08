#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

static bool comp(int a, int b)
{
	string A = "";
	string B = "";
	A += to_string(a);
	A += to_string(b);
	B += to_string(b);
	B += to_string(a);

	return A < B;
}

string PrintMinNumber(vector<int> numbers)
{
	string res;
	if (numbers.empty())
		return res;
	if (numbers.size() == 1)
	{
		res = to_string(numbers[0]);
		return res;
	}
	else
	{
		sort(numbers.begin(), numbers.end(), comp);
		for (int i = 0; i < numbers.size();i++)
		{
			res += to_string(numbers[i]);
		}
		return res;
	}
}

int main()
{
	vector<int> numbers = { 3, 32, 31 };
	string s = PrintMinNumber(numbers);
	cout << s << endl;

	system("pause");
	return 0;
}
