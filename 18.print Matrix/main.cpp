#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int> > vec, int row_start, int row_end, int col_start, int col_end)
{
	if (row_start == 0 && row_end == 0)
		cout << endl;

}

void print_circel(vector<vector<int> > vec, int startX, int startY, int width, int height, vector<int> &res)
{
	int endX = width - 1 - startX;
	int endY = height - 1 - startY;

	for (int i = startX; i <= width - startX - 1; i++)
		res.push_back(vec[startY][i]);

	if(endY > startY)
	{
		for (int i = startY + 1; i <= height - startY - 1; i++)
			res.push_back(vec[i][width - startX - 1]);
	}
	if (endX > startX && endY > startY)
	{
		for (int i = width - startX - 2; i >= startX; i--)
			res.push_back(vec[height - startY - 1][i]);
	}
	if (endX > startX && endY > startY-1)
	{
		for (int i = height - startY - 2; i > startY; i--)
		res.push_back(vec[i][startX]);
	}
}

vector<int> printMat(vector<vector<int> > vec)
{
	int width = vec[0].size();
	int height = vec.size();
	vector<int> res;
	int startX = 0, startY = 0;
	if (width == 1)
	{
		for (int i = 0; i < height; i++)
			res.push_back(vec[i][0]);
		return res;
	}
	if (height == 1)
	{
		for (int i = 0; i < width; i++)
			res.push_back(vec[0][i]);
		return res;
	}
	else
	{
		while (width > startX * 2 && height > startY * 2)
		{
			print_circel(vec, startX, startY, width, height, res);
			startX++;
			startY++;
		}
	}
	return res;
	//for (int i = 0; i < res.size(); i++)
	//	cout << res[i] << " ";
	//cout << endl;
}

int main()
{
	//vector<vector<int> > v = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 }, { 17, 18, 19, 20 } };
	//vector<vector<int> > v = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	//vector<vector<int> > v = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12} };
	//vector<vector<int> > v = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	//vector<vector<int> > v = { { 1 }, { 2 }, { 3 }, { 4 } };
	//vector<vector<int> > v = { { 1, 2, 3, 4, 5 } };
	//vector<vector<int> > v = { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 }, { 11, 12, 13, 14, 15 } };
	//vector<vector<int> > v = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 }, { 13, 14, 15 } };
	vector<vector<int> > v = { { 1, 2, 3, 4, 5, 6 }, { 7, 8, 9, 10, 11, 12 }, { 13, 14, 15, 16, 17, 18 },
								{ 19, 20, 21, 22, 23, 24 } };

	vector<int> res = printMat(v);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	//cout << endl;
	cout << endl;

	system("pause");
	return 0;
}
