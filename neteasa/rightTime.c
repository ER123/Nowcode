#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<ctype.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>
#include<time.h>
using namespace std;
void fre() { freopen("c://test//input.in", "r", stdin); freopen("c://test//output.out", "w", stdout); }
#define MS(x, y) memset(x, y, sizeof(x))
#define ls o<<1
#define rs o<<1|1
typedef long long LL;
typedef unsigned long long UL;
typedef unsigned int UI;
template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b > a)a = b; }
template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b < a)a = b; }
const int N = 0, M = 0, Z = 1e9 + 7, inf = 0x3f3f3f3f;
template <class T1, class T2>inline void gadd(T1 &a, T2 b) { a = (a + b) % Z; }
int casenum, casei;
int h, m, s;
char S[10];
int a[10], b[10];
struct ANS
{
	int h, m, s;
}ans;
 
//简单做法
void simple()
{
	int h, m, s;
	scanf("%d:%d:%d", &h, &m, &s);
	if (h >= 24)h %= 10;
	if (m >= 60)m %= 10;
	if (s >= 60)s %= 10;
	printf("%02d:%02d:%02d\n", h, m, s);
}
 
//复杂暴力做法
void complex()
{
	scanf("%s", S);
	a[0] = S[0] - 48;
	a[1] = S[1] - 48;
	a[2] = S[3] - 48;
	a[3] = S[4] - 48;
	a[4] = S[6] - 48;
	a[5] = S[7] - 48;
	//60 * 60 * 24
	int ansdif = inf;
	for (int i = 0; i < 24; ++i)
	{
		b[0] = i / 10;
		b[1] = i % 10;
		for (int j = 0; j < 60; ++j)
		{
			b[2] = j / 10;
			b[3] = j % 10;
			for (int k = 0; k < 60; ++k)
			{
				b[4] = k / 10;
				b[5] = k % 10;
 
				int dif = 0;
				for (int u = 0; u <= 5; ++u)
				{
					dif += (a[u] != b[u]);
				}
				if (dif < ansdif)
				{
					ansdif = dif;
					ans = { i,j,k };
				}
			}
		}
	}
	printf("%02d:%02d:%02d\n", ans.h, ans.m, ans.s);
}
int main()
{
	scanf("%d", &casenum);
	for (casei = 1; casei <= casenum; ++casei)
	{
		simple();
	}
	return 0;
}
/*
【题意】
略
【分析】
可以直接暴力枚举所有时刻取一个最优的。
也可以对时、分、秒 三个数整体判定，如果不合法，把数的十位数变成0即可。
【时间复杂度&&优化】
O（1）
*/
