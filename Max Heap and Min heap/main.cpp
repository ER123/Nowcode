#include <iostream>
#include "MinHeap.h"
#include "MaxHeap.h"
using namespace std;

int main()
{
	int a[10] = { 4, 3, 5, 6, 8, 7, 2, 1, 9, 0 };
	MinHeap<int> h;
	MinHeap<int> h1(a, 10);
	int x = 1;
	h1.insert(x);
	h1.removeMin(x);

	int i = 0;
	cout << "MinHeap:" << endl;
	while (i<10)
	{
		cout << h1.heap[i] << " ";
		i++;
	}
	cout << endl;

	MaxHeap<int> h2(a, 10);
	
	i = 0;
	cout << "MaxHaep:" << endl;
	while (i < 10)
	{
		cout << h2.heap[i] << " ";
		i++;
	}
	cout << endl;
	system("pause");
	return 0;
}
