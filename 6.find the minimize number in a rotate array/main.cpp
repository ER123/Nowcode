#include <iostream>
#include <vector>
#include <time.h>

int minNumberInRotateArray(std::vector<int> rotateArray) {
	int len = rotateArray.size();
	if (len == 0)
		return 0;
	if (len == 1)
		return rotateArray[0];

	int head = 0;
	int tail = len - 1;

	if (rotateArray[head] < rotateArray[tail])
		return rotateArray[head];

	int flag = (head + tail) / 2;

	while (head < tail){
		if (head == tail - 1)
		{
			if (rotateArray[head] < rotateArray[tail])
				return rotateArray[head];
			else
				return rotateArray[tail];
		}
		if (rotateArray[head] <= rotateArray[flag]){
			head = flag;
			flag = (head + tail) / 2;
		}
		else if (rotateArray[head] >= rotateArray[flag])
		{
			tail = flag;
			flag = (head + tail) / 2;
		}
	}
	return rotateArray[head];
}

int main()
{
	double duration;
	clock_t start, finish;
	start = clock();

	std::vector<int> vec;
	for (int i = 399; i < 7000; i++)
	{
		vec.push_back(i);
		vec.push_back(i);
	}
	for (int i = 0; i < 100; i++)
	{
		vec.push_back(i);
		vec.push_back(i);
		vec.push_back(i);
		vec.push_back(i);
	}
	finish = clock();
	duration = double(finish - start) / CLOCKS_PER_SEC;
	std::cout << "time1: " << duration << std::endl;

	start = clock();
	int res = minNumberInRotateArray(vec);

	finish = clock();
	duration = double(finish - start) / CLOCKS_PER_SEC;
	std::cout << "time2: " << duration << std::endl;

	std::cout << res << std::endl;
	return 0;
}
