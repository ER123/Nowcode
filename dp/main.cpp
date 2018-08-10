#include <iostream>
#include <string>

using namespace std;

int findMinCoin(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else if (n == 3)
		return 2;
	else if (n == 4)
		return 2;
	else if (n == 5)
		return 1;
	int coin_has[3] = { 1, 2, 5 };
	int min = n;
	for (int i = 6; i <= n; i++)
	{
		min = n;
		for (int j = 0; j < 3; j++)
		{
			int num = findMinCoin(i - coin_has[j]) + 1;
			if (num < min)
				min = num;
		}
	}
	return min;
}

struct coord
{
	int x;
	int y;
};
coord mycoord[4][8] = { 0 };//行走路径

//每个格子苹果数量
int n = 3, m = 7; 
int A[4][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 1, 2, 4, 3, 5, 2, 4 }, { 0, 2, 5, 1, 2, 5, 2, 2 }, { 0, 4, 4, 3, 5, 1, 2, 3 } };
int M[4][8];//记录每个坐标得到最多的苹果数

int apple(int x, int y)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j<=m; j++)
		{
			if (i == 1 && j == 1)
			{
				M[1][1] = A[1][1];
			}
			if (i == 1 && j != 1)
			{
				M[i][j] = M[i][j - 1] + A[i][j];
			}
			if (x != 1 && y == 1)
			{
				M[i][j] = M[i - 1][j] + A[i][j];
			}
			else if (i!=1 && j!=1)
			{
				if (A[i][j - 1] > A[i - 1][j])
				{
					M[i][j] = M[i][j-1] + A[i][j];
				}
				else
				{
					M[i][j] = M[i - 1][ j] + A[i][j];
				}
			}
		}
	}
	return 0;
}

int main()
{
	//int min = findMinCoin(15);
	//cout << min << endl;

	apple(1, 2);
	for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= 5; i++)
	{
		cout << mycoord[i].x << " " << mycoord[i].y << endl;
	}

	system("pause");
	return 0;
}
