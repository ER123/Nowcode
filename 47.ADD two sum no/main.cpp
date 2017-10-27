int ADD_two_sum(int n1, int n2)
{
	int res1 = n1^n2;
	int res2 = n1&n2;
	res2 = res2 << 1;
	while (res2!=0)
	{
		int res1_tem = res1;
		int res2_tem = res2;
		res1 = res1_tem^res2_tem;
		res2 = res1_tem&res2_tem;
		res2 = res2 << 1;
	}
	return res1;
}
