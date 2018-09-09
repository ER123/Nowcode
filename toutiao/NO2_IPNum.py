#给定一个不带'.'的IP地址字符串，能组成合法IP的个数

import sys

def main():
    s = input()
    lens = len(s)
    if lens < 4 or lens > 12:
        print(0)
        return ""
    if lens == 4:
        print(1)
        return ""
    dp = [[0 for i in range(5)] for i in range(lens+3)]
    dp[lens][4] = 1
    for part in  range(3, -1, -1):
        i = lens - 1
        while i >= part:
            dp[i][part] = dp[i+1][part+1]
            #print(s[i], '0')
            if s[i] != '0':
                dp[i][part] += dp[i+2][part+1]
                if i+2<lens:
                    #print("s[i]:",int(s[i]), s[i])
                    #print(int('0'))
                    sum = (int(s[i]) - int('0'))*100 + (int(s[i+1]) - int('0'))*10 + (int(s[i+2])-int('0'))
                    if sum < 256:
                        dp[i][part] += dp[i+3][part+1]
            i = min(i-1, part*3)
    print(dp[0][0])

if __name__ == '__main__':
    main()
