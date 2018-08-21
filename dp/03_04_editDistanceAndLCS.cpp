#include <iostream>
#include <string>

using namespace std;

string s1;
string s2;
int Distance[100][100] = { 0 };

int findMin(int a1, int a2, int a3)
{//比较三个数中的最小数
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
			if (s1[i-1] == s2[j-1])//当前字符相等时，上一个长度加1
				Distance[i][j] = Distance[i - 1][j - 1];
			else                   //当前字符不等时，三个方向上最小的加1
			{
				Distance[i][j] = 1 + findMin(Distance[i - 1][j - 1], Distance[i - 1][j], Distance[i][j - 1]);
			}
		}
	}
}

//最长公共子序列
int LCSres[100][100] = { 0 };
void LCS(int len1, int len2)
{
	for (int i = 0; i <= len2; i++)//一个字符串为空时，子序列长度为0
	{
		LCSres[0][i] = 0;
	}
	for (int j = 0; j <= len1; j++)//一个字符串为空时，子序列长度为0
	{
		LCSres[j][0] = 0;
	}
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (s1[i - 1] == s2[j - 1])//当前字符串相等时，子序列长度加1
			{
				LCSres[i][j] = LCSres[i - 1][j - 1] + 1;
			}
			else if (LCSres[i - 1][j] >= LCSres[i][j - 1])//否则选择较长的作为子序列长度
			{
				LCSres[i][j] = LCSres[i - 1][j];
			}
			else
			{
				LCSres[i][j] = LCSres[i][j - 1];
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
	
	LCS(len1, len2);
	cout << LCSres[len1][len2] << endl;

	return 0;
}
