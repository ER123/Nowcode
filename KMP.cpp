#include <iostream>
#include <string>

using namespace std;

int *next_f(string t, int *next)
{//找到目标数组的最大前缀和后缀匹配
	next[0] = -1;//-1代表未匹配
	int len = t.length();
	int k = -1;
	for (int i = 1; i < len; i++)
	{
		while (k > 0 && t[i] != t[k])//如果在当前位置前后缀未匹配，则回溯next数组，减小匹配数进行匹配
		{
			k = next[k];//回溯
		}
		if (t[i] == t[k+1])//如果当前位置匹配，继续向下进行匹配
			k++;
		next[i] = k;//把当前位置求得最大匹配值赋给next
	}
	return next;
}

int find_t(string s, string t, int *next)
{
	int len_t = t.length();
	int len_s = s.length();

	int k = -1;
	int i = 0;

	for (i = 0; i < len_s; i++)
	{
		while (k>-1 && s[i] != t[k+1])
		{//当前位置未匹配成功，target往前移动到前一段匹配位置再次进行匹配，直到target最前端或者匹配到某一位置
			k = next[k];
		}
		if (s[i] == t[k + 1])
			k++;
		if (k == len_t - 1)
			return i - len_t + 1;
	}
	return -1;
}

int main()
{
	string s = "ABCDABABCDABD";
	string t = "ABCDABD";
	int len = t.length();

	int *next = (int *)malloc(sizeof(int) * len);

	next = next_f(t, next);
	int location = find_t(s, t, next);

	cout << "At " << location << " in source find target!" << endl;

	return 0;
}
