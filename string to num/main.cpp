class Solution {
public:
    int StrToInt(string str) {
        int len = str.length();
        if(len == 0)
            return 0;
        int i=0;
        int flag = 1;
        long long res = 0;
        while(i<len){
            if(i == 0){
                if(str[i] == '-')
                	flag = 0;
                else if(str[i] == '+')
                    flag = 1;
                else if(str[i] >= '0' && str[i] <= '9')
                    res = str[i] - '0';
                else
                    return 0;
            }
            else{
                if(str[i] >= '0' && str[i] <= '9'){
                    res = res*10 + str[i] - '0';
                }
                else
                    return 0;
            }
            i++;
        }
        return flag == 1 ? res : -res;
    }
};
