#include <iostream>
#include <string>

using namespace std;

string s1;
string s2;
int Distance[100][100] = { 0 };

int findMin(int a1, int a2, int a3)
{
	if (a1 < a2)
	{
		if (a1 < a3)
			return a1;
	}
	else
	{
		if (a2 < a3)
			return a2;
	}
	return a3;
}
void editDistance(int len1, int len2)
{
	for (int i = 0; i <= len1; i++)//s2为空串时，s1与s2的距离就是s1的长度
	{
		Distance[0][i] = i;
	}
	for (int j = 0; j <= len2; j++)//s1为空串时，s1与s2的距离就是s2的长度
	{
		Distance[j][0] = j;
	}

	for (int i = 1; i <= len1; i++)//非空串开始
	{
		for (int j = 1; j <= len2; j++)
		{
			if (s1[i-1] == s2[j-1])//当前字符相等时
				Distance[i][j] = Distance[i - 1][j - 1];
			else                   //当前字符不等时
			{
				Distance[i][j] = 1 + findMin(Distance[i - 1][j - 1], Distance[i - 1][j], Distance[i][j - 1]);
			}
		}
	}
}

int main()
{
	cin >> s1 >> s2;
	int len1 = s1.length();
	int len2 = s2.length();
	editDistance(len1, len2);
	cout << Distance[len1][len2] << endl;

	return 0;
}
