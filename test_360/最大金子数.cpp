#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	cin >> T;
	int n;
	int no = 0;
	while (T--)
	{
		no++;
		cin >> n;
		int* a = new int[n + 1];
		int* sum = new int[n + 1];
		int** dp = new int*[n + 1];
		for (int i = 0; i <= n; i++)
		{
			dp[i] = new int[n + 1];
			for (int j = 0; j <= n; j++)
				dp[i][j] = 0;
			sum[i] = 0;
		}
		int temp;
		for (int i = 1; i <= n; i++)
		{
			cin >> temp;
			a[i] = temp;
			sum[i] = sum[i - 1] + temp;
			dp[i][i] = temp;
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j + i <= n; j++)
			{
				int sum_reduce = sum[i + j] - sum[j - 1];
				int min_temp = min(dp[j][i + j - 1], dp[j + 1][i + j]);
				int max = sum_reduce - min_temp;
				dp[j][i + j] = max;
			}
		}
		cout << "Case #" << no << ": " << dp[1][n] <<" " << sum[n] - dp[1][n] <<endl;
	}
	//system("pause");
	return 0;
}
