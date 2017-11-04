#include <iostream>
#include <vector>

using namespace std;

int NumberOf1Between1AndN(int n)
{
	int i = 0;
	int res = 0;
	for (i = 1; i <= n; i *= 10)
		res += (n / i + 8) / 10 * i + (n / i % 10 == 1)*(n%i + 1);
	return res;
}

int main()
{
	int n;
	cin >> n;
	int res = NumberOf1Between1AndN(n);
	cout << res << endl;

	system("pause");
	return 0;
}
