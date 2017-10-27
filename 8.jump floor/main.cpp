#include <iostream>

using namespace std;

int step = 0;
int num = 0;
int jumpFloor(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	else
	{
		int x = 1, y = 2, z;
		for (int i = 3; i <= n; i++)
		{
			z = x + y;
			x = y;
			y = z;
		}
		return z;
	}
}

int main()
{
	int n;
	cin >> n;
	int res = jumpFloor(n);
	cout << res << endl;

	system("pause");
	return 0;
}
