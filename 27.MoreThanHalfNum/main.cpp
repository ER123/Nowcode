#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) 
{
	if (numbers.empty())
		return 0;

	int len = numbers.size();
	if (len == 1)
		return numbers[0];

	sort(numbers.begin(), numbers.end());
	int i = 0;
	while (i<len/2)
	{
		if (numbers[i] == numbers[i + len / 2])
		{
			return numbers[i];
		}
		i++;
	}
	return 0;
}

bool checkMoreThanHalf(vector<int> numbers, int length, int result)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] == result)
			count++;
	}
	if (count * 2 <= length)
		return false;
	return true;
}

int MoreThanHalfNum_Solution_1(vector<int> numbers)
{
	if (numbers.size() == 0)
		return 0;
	int len = numbers.size();
	if (len == 1)
		return numbers[0];
	int i = 1;
	int temp = numbers[0];
	int count = 1;
	int res;
	while (i<len)
	{
		if (count == 0)
		{
			temp = numbers[i];
			count++;
		}

		else{
			if (numbers[i] == temp)
				count++;
			else
				count--;
		}
		i++;
	}
	if (!checkMoreThanHalf(numbers, len, temp))
		return 0;

	return temp;
}

int main()
{
	vector<int> v;
	int number;
	while (cin>>number)
	{
		v.push_back(number);
	}
	int res = MoreThanHalfNum_Solution(v);
	cout << res << endl;

	int res1 = MoreThanHalfNum_Solution_1(v);
	cout << res1 << endl;

	system("pause");
	return 0;
}
