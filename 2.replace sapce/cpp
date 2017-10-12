//先计算str长度，找到空格数，然后从尾到头进行替换
class Solution {
public:
	void replaceSpace(char *str,int length) {
		if (str == NULL || length < 0)
		return;
		int i = 0;
		int str_length = 0;
		int sapce_count = 0;
		while (str[i] != '\0')
		{
			str_length++;
			if (str[i] == ' ')
			{
				sapce_count++;
			}
			i++;
		}
		int all_length = str_length + sapce_count*2;
		if (all_length > length)
			return;
		int pOld = str_length;
		int pNew = all_length;
		while (pOld >= 0 && pNew > pOld)
		{
			if (str[pOld] == ' ')
			{
				str[pNew--] = '0';
				str[pNew--] = '2';
				str[pNew--] = '%';
			}
			else
			{
				str[pNew--] = str[pOld];
			}
			pOld--;
		}
	}
};
