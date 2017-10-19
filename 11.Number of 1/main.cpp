/*1、常规解法：正数直接模2余数，等于1该位上为1，等于0该位上数字为0*/
int number_of_pos(int n)
{
	while (n != 0)
	{
		if (n % 2 == 1)
		{
			count1++;
		}
		n = n / 2;
	}
	return count1;
}

int number_of_1(int n)
{
	if (n = INT_MIN)
		return 1;
	if (n < 0)
	{
		int nn = -n;
		if (nn % 2 == 1)
		{
			return 32 - number_of_pos(nn) + 1;
		}
		else
		{
			return 32 - number_of_pos(nn);
		}
	}
	else
		return number_of_pos(n);
}

/*2、n&(n-1)可求得1中的个数，*/
public class Solution {
    public int NumberOf1(int n) {
        int count = 0;
        while(n!= 0){
            count++;
            n = n & (n - 1);
         }
        return count;
    }
}

/*3、用1从右往左一次相与求得1的个数*/
int NumberOf1(int n)
{
    int count = 0;
    int flag = 1;
    while(flag!=0)
    {
        if((n&flag) == 1)
        {
            count++;
        }
        flag = flag<<1;
    }
    return count;    
}
