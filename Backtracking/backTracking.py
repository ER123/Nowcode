################################################################
#bool finished = FALSE; /* 是否获得全部解? */
#backtrack(int a[], int k, data input)
#{
#    int c[MAXCANDIDATES]; /*这次搜索的候选 */
#    int ncandidates; /* 候选数目 */
#    int i; /* counter */
#    if (is_a_solution(a,k,input))
#	    process_solution(a,k,input);
#    else {
#        k = k+1;
#        construct_candidates(a,k,input,c,&ncandidates);
#        for (i=0; i<ncandidates; i++) {
#            a[k] = c[i];
#            make_move(a,k,input);
#            backtrack(a,k,input);
#            unmake_move(a,k,input);
#            if (finished) return; /* 如果符合终止条件就提前退出 */
#        }
#    }
#}
###############################################################
import os
import sys

#1.找出集合的所有子集
s = [1,2,3,4,5]
len_s = len(s)
c = [0 for i in range(len_s)]
def printS(c):
	for i in range(len_s):
		if c[i]:
			sys.stdout.write(str(s[i])+ ' ')
	sys.stdout.write("\n")

def findAllSubset(i):
	global res_num
	if i == len_s:
		printS(c)
		return ""
	else:
		c[i] = 0
		findAllSubset(i+1)
		c[i] = 1
		findAllSubset(i+1)

#2.八皇后问题
Q = [[0 for i in range(8)] for i in range(8)]
sum = 0
def eightQueens(row):
	global sum
	if row >= 8:
		sum+=1
		print(sum)
		printQ()
		return ""
	else:
		for i in range(8):
			if canMove(row, i):
				Q[row][i] = 1
				eightQueens(row+1)
				Q[row][i] = 0
	return ""

def canMove(row, col):
	for i in range(row):#同列
		if Q[i][col] == 1:
			return False 
	for i,j in zip(range(row, -1, -1), range(col, -1, -1)):#左上角
		if Q[i][j] == 1:
			return False 
	for i, j in zip(range(row,-1, -1), range(col, 8, 1)):#右上角
		if Q[i][j] == 1:
			return False
	return True

def printQ():
	for i in range(8):
		for j in range(8):
			sys.stdout.write(str(Q[i][j]) + " ")
		sys.stdout.write("\n")

#3.求图中的连通块数与连通区域最大值
P=[ [0,0,0,1,1,1,0,0],
	[0,0,0,1,1,1,0,0],
	[0,0,0,1,0,1,0,1],
	[1,0,0,1,1,1,0,1],
	[0,0,0,0,0,0,0,1],
	[0,1,0,1,1,0,0,0],
	[0,0,0,1,1,1,0,0],
	[0,0,0,1,1,1,0,0]]
funs = []
def findSumOfFuns():
	sumOfTeams = 0
	sumOfFuns = 0
	maxFuns = 0 
	for i in range(8):
		for j in range(8):
			if P[i][j] == 1:
				help(i,j, sumOfFuns)
				#print(sumOfFuns)
				sumOfTeams += 1
	
	for i in range(len(funs)):
		if funs[i] > maxFuns:
			maxFuns = funs[i]
	print(maxFuns, sumOfTeams)

def help(i,j, sumOfFuns):
	if(i <0 or i >= 8 or j<0 or j>= 8 or P[i][j] != 1):
		return ""
	P[i][j] = -1
	sumOfFuns += 1
	funs.append(sumOfFuns)
	help(i-1,j,sumOfFuns)
	help(i,j-1,sumOfFuns)
	help(i+1, j,sumOfFuns)
	help(i,j+1,sumOfFuns)
	help(i+1, j+1,sumOfFuns)
	help(i-1, j-1,sumOfFuns)
	help(i-1, j+1,sumOfFuns)
	help(i+1, j-1,sumOfFuns)

if __name__ == '__main__':
	#findAllSubset(0)
	#eightQueens(0)
	findSumOfFuns()
