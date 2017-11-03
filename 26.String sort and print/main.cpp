#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(char *a, char *b)
{
	char c;
	c = *a;
	*a = *b;
	*b = c;
}

void bubblesort(char *arr, int begin, int length)
{
	for (int i = begin; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
		}
	}
}

void allPrint(char *arr, int k, int length, vector<string> &v)
{
	if (k == length)
	{
		v.push_back(arr);
	}
	else
	{
		for (int i = k; i < length;i++)
		{
			if (i != k && arr[i] == arr[k])
				continue; 
			swap(&arr[i], &arr[k]);
			bubblesort(arr, k + 1, length);
			allPrint(arr, k + 1, length, v);
			bubblesort(arr, k + 1, length);
		}
	}
}

vector<string> Permutation(string str)
{
	vector<string> v;
	if (str.length() == NULL)
		return v;
	int len = str.length();
	char *s = new char[len];
	int i = 0;
	while (i<len)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	char *pStr = s;
	allPrint(pStr, 0, len, v);
	return v;
}

int main()
{
	string str;
	cin >> str;
	vector<string> res = Permutation(str);

	return 0;
}
