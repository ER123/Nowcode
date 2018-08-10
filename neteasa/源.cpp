#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n, ans = 0;
	int tax[7] = {5000, 8000, 17000, 30000, 40000, 60000, 85000};
	float rate[7] = { 0.03, 0.1, 0.2, 0.25, 0.3, 0.35, 0.45 };
	cin >> n;
	for (int i = 0; i < n; i++){
		int x; 
		ans = 0;
		scanf("%d", &x);
		if (x <= 5000)
			cout << "0" << endl;
		else
		{
			for (int j = 6; j >= 0; j--)
			{
				if (x - tax[j] > 0)
				{
					float temp = (x - tax[j])*rate[j];
					ans += round(temp);
					x = tax[j];
				}
			}
			cout << ans << endl;
		}	
	}
	system("pause");
	return 0;
}