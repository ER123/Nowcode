#include <iostream>
#include <time.h>
using namespace std;

//int GetUglyNumber_Solution(int index) 
//{
//	if (index < 7)
//	{
//		return index;
//	}
//	int number = 7;
//	int i = 7;
//	while (i <= index)
//	{
//		number++;
//		int temp = number;
//		while (temp != 1)
//		{
//			if (temp % 2 == 0)
//				temp = temp / 2;
//			else if (temp % 3 == 0)
//				temp = temp / 3;
//			else if (temp % 5 == 0)
//				temp = temp / 5;
//			else
//				break;
//		}
//		if (temp == 1)
//			i++;
//	}
//
//	return number;
//}

int findMin(int a, int b, int c)
{
	int min = (a < b) ? a : b;
	min = (min < c) ? min : c;
	return min;
}

int GetUglyNumber_Solution(int index)
{
	if (index <= 1)
	{
		return 0;
	}
	int *pUglyNumber = new int[index];
	pUglyNumber[0] = 1;
	int i = 1;
	int *t2 = pUglyNumber;
	int *t3 = pUglyNumber;
	int *t5 = pUglyNumber;
	int M = 1;
 	while (i<index)
	{
		M = findMin(*t2*2, *t3*3, *t5*5);
		pUglyNumber[i] = M;

		while (*t2 * 2 <= pUglyNumber[i])
			++t2;
		while (*t3 * 3 <= pUglyNumber[i])
			++t3;
		while (*t5 * 5 <= pUglyNumber[i])
			++t5;
		++i;
	}
	return M;
}

int main()
{
	int index;
	cin >> index;
	clock_t t0, t1;
	t0 = clock();
	int res = GetUglyNumber_Solution(index);
	t1 = clock();
	cout << res << endl;
	cout << t1 - t0 << " ms " << endl;

	system("pause");
	return 0;
}
