#一个M*N的矩阵，上下左右相邻的1看作同一组，求总共相邻块的个数
#
import sys
import os

company = []

def dfs(i, j):
    if i<0 or i>len(company) - 1 or j<0 or j>len(company[0]) - 1 or company[i][j] == 0:
        return ""
    company[i][j] = 0
    dfs(i-1, j)
    dfs(i, j-1)
    dfs(i+1, j)
    dfs(i, j+1)

def main():
    M = int(input())
    for i in range(M):
        line = list(map(int, input().split(" ")))        
        company.append(line)
    res = 0
    for i in range(M):
        for j in range(M):
            if company[i][j] == 1:
                dfs(i, j)
                print(company)
                res += 1
    print(res)

if __name__ == "__main__":
    main()
