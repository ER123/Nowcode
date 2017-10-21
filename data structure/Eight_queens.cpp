#include <iostream>

#define SIZE 8

using namespace std;

int count1 = 0;

void print_chess(int chess[][SIZE])
{
	cout << "the " << count1 << " answer:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << chess[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool place(int chess[][SIZE], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (chess[i][col] == 1 || ((chess[i][j] == 1) && (abs(i - row) == abs(j - col))))
				return false;
		}
	}
	return true;
}

void eight_queen(int chess[][SIZE], int row)
{
	if (row >= SIZE)
	{	
		count1++;
		print_chess(chess);
	}
	else
	{
		for (int col = 0; col < SIZE; col++)
		{
			if (place(chess, row, col))
			{
				chess[row][col] = 1;
				eight_quene(chess, row + 1);
				chess[row][col] = 0;
			}
		}
	}
}

int main()
{
	int chess[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			chess[i][j] = 0;
		}
	}

	int row = 0;

	eight_queen(chess, row);

	cout << "Total answer's number is " << count1 << endl;
	system("pause");

	return 0;
}
