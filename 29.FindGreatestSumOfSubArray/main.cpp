#include <iostream>
#include <vector>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) 
{
	int res = 0;
	int temp = 0;
	if (array.size() == 0)
		return 0; 

	int i = 0;
	while (i<array.size())
	{
		temp += array[i];
		if (temp < 0)
		{
			if (res > 0)
				temp = 0;
			else if (res < array[i] || res == 0)
				res = array[i];
		}
		else
		{
			if (temp > res)
				res = temp;
		}
		i++;
	}

	return res;
}

int main()
{
	vector<int> v = { 1, -2, 3, 10, -4, 7, 2, -5 };
	//vector<int> v = { 6, -3, -2, 7, -15, 1, 2, 2 };
	//vector<int> v = { -9,-2,-1, -2, -4, -5, -6, -7, -8 };
	//vector<int> v = { 2, 3, 4, 5, 6, 7, 8 };
	int res = FindGreatestSumOfSubArray(v);
	cout << res << endl;

	system("pause");
	return 0;
}
