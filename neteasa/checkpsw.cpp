// 本题为考试多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string b = "abcdefghiiklmnopqrstuvwxyz";
string c = "!@#$%^&*()_-=+[]{},.<>/?";
string d = "0123456789";
string e[] = { "password", "admin", "qwerty", "hello", "iloveyou", "112233" };
string f[] = { "ABC", "BCD", "CDE", "DEF", "EFG", "FGH", "GHI", "HIJ", "IJK", "JKL", "KLM", "LMN", "MNO", "NOP", "OPQ", "PQR", "QRS", "RST", "STU", "TUV", "UVW", "VWX", "WXY", "XYZ" };
string g[] = { "abc", "bcd", "cde", "def", "efg", "fgh", "ghi", "hij", "ijk", "jkl", "klm", "lmn", "mno", "nop", "opq", "pqr", "qrs", "rst", "stu", "tuv", "uvw", "vwx", "wxy", "xyz" };
string h[] = { "000", "111", "222", "333", "444", "555", "666", "777", "888", "999", "012", "123", "234", "345", "456", "567", "678", "789", "024", "246", "468", "135", "357", "579", "036", "369", "147", "258", "048", "159" };

bool check2(string str, int len)//检查是否同时含有大小写字母，数字，特殊字符
{
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	int flag4 = 0;
	for (int i = 0; i < len; i++){
		//cout << str[i] << endl;
		if (flag1 == 0 && (a.find(str[i]) != string::npos)){//大写字母
			flag1 = 1;
		}
		if (flag2 == 0 && (b.find(str[i]) != string::npos)){//小写字母
			flag2 = 1;
		}
		if (flag3 == 0 && (c.find(str[i]) != string::npos)){//特殊字符
			flag3 = 1;
		}
		if (flag4 == 0 && (d.find(str[i]) != string::npos)){//数字
			flag4 = 1;
		}
		//cout << flag1 << " " << flag2 << " " << flag3 << " " << flag4 << endl;
	}
	if (flag1==1 && flag2==1 && flag3==1 && flag4==1){
		//cout << "check2: " << "true" << endl;
		return true;
	}
	else
		return false;
}

bool check3(string str)//等差数列
{
	int flag = 0;
	for (int i = 0; i < 30; i++){
		//cout << h[i] << endl;
		if (flag == 0 && (str.find(h[i]) != string::npos)){
			flag = 1;
		}
	}
	//cout << "check3: " << flag << endl;
	if (flag == 1){
		return false;
	}
	else
		return true;
}

bool check4(string str)//字母有序
{
	int flag = 0;
	for (int i = 0; i < 24; i++){
		//cout << f[i] << " " << g[i] <<endl;
		if (flag == 0 && ((str.find(f[i]) != string::npos) || (str.find(g[i]) != string::npos))){
			flag = 1;
		}
	}
	//cout << "check4: " <<flag << endl;
	if (flag == 1){
		return false;
	}
	else
		return true;
}

bool check5(string str)//常见字符
{
	int flag = 0;
	for (int i = 0; i < 6; i++){
		//cout << e[i] << endl;
		if (flag == 0 && (str.find(e[i]) != string::npos)){
			flag = 1;
		}
	}
	//cout << "check5: " << flag << endl;
	if (flag == 1){
		return false;
	}
	else
		return true;
}

int main(){
	int n, ans = 0;
	string paswad;

	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> paswad;
		int len = paswad.length();
		//if (len < 8){
		//	cout << "no" << endl;
		//}
		//else if (check2(paswad, len) == false){
		//	cout << "no" << endl;
		//}
		//else if (check3(paswad) == false){
		//	cout << "no" << endl;
		//}
		//else if (check4(paswad) == false){
		//	cout << "no" << endl;
		//}
		//else if (check5(paswad) == false){
		//	cout << "no" << endl;
		//}
		//else
		//	cout << "yes" << endl;

		if (len >= 8 && check2(paswad, len) && check3(paswad) && check4(paswad) && check5(paswad))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}