#1、割绳子将长度为n的绳子切位m段使这m段绳子的长度乘积最大
def findTheLongsetLine(n):
	#先对边界情况求解
	if n < 2:
		return 0
	elif n == 2:
		return 1
	elif n == 3:
		return 2
	
	h = [0]*50
	h[0] = 0
	h[1] = 1
	h[2] = 2
	h[3] = 3
	#f(n) = max{f(i)*f(n-i)}
	for i in range(4,n+1):
		print("i:", i)
		max = 0
		for j in range(1, i//2+1):
			mult = h[j]*h[i-j]
			print("j:%d, mult:%d"%(j, mult))
			if mult > max:
				max = mult
			h[i] = max
		print("h[%d]:%d"%(i,h[i]))	
		print(h)
	return h[n]

def findCoin(n):
	#首先处理边界情况
	if n == 0:
		return 0
	elif n == 1:
		return 1
	elif n == 2:
		return 2
	elif n == 3:
		return 1
	elif n == 4:
		return 2
	elif n == 5:
		return 1
	'''
	minx = n
	for j in ([1,3,5]):
		num = findCoin(n-j) + 1#采用递归方法
		if minx > num:
			minx = num
	'''
	for i in range(6, n+1):
		minx = n
		for j in ([1,3,5]):
			num = findCoin(i - j) + 1 #	 从下向上的解决思维
			if minx > num:
				minx = num

	return minx

def upstair(n):
	if n <= 0:
		return 0
	if n == 1:
		return 1
	if n == 2:
		return 2
	h = [0]*100

	#h[n] = upstair(n-1) + upstair(n-2)

	#自底而上的解决方法
	h[0] = 0
	h[1] = 1
	h[2] = 2
	for i in range(3, n+1):
		h[n] = upstair(n - 1) + upstair(n - 2)

	#print(h[n], n)#, minx)
	return h[n]

#最长公共子序列
import numpy as np 
def LCS(len1, len2):	
	len1 = len(str1)
	len2 = len(str2)
	if len1 == 0 or len2 == 0:
		return 0
	#res = [[-1]*(len1+1)]*(len2+1)#浅拷贝
	res = [[0 for i in range(len1+1)] for i in range(len2+1)]
	path = [[" " for i in range(len1)] for i in range(len2)]
	for i in range(len1+1):
		res[0][i] = 0
	for j in range(len2+1):
		res[j][0] = 0
	for i in range(1, len2+1):
		for j in range(1, len1+1):
			if str2[i-1] == str1[j-1]:
				res[i][j] = res[i-1][j-1] + 1
				path[i-1][j-1] = "lu"
			elif res[i-1][j] >= res[i][j-1]:
				res[i][j] = res[i-1][j]
				path[i-1][j-1] = "u"
			else:
				res[i][j] = res[i][j-1]
				path[i-1][j-1] = "l"
	for i in range(len2+1):
		print(res[i])
	print(res[len2][len1])
	for i in range(len2):
		print(path[i])
	word = ""
	print(str1, str2)
	findPath(path, len2-1, len1-1, word, str1)#回溯寻找最长公共子序列
def findPath(path, i, j, word, str1):
	print("i:%d, j:%d"%(i,j))
	if i == 0 or j == 0:
		if path[i][j] == "lu":
			word+=str1[i]
		print(word)
		return ""

	if i>0 and j >0:
		if path[i][j] == 'lu':
			word += str1[j]
			findPath(path, i-1, j-1, word,str1)
		elif path[i][j] == 'u':
			findPath(path, i-1, j, word, str1)
		else:
			findPath(path, i, j-1, word, str1)
#求最长递增子序列
def LIS(s):
	len_s = len(s)
	if len_s == 0:
		print(len_s)
	else:	
		lis = [1]*len_s
		len_max = 1
		for i in range(1,len_s):
			for j in range(1, i):
				if s[i] > s[j] and lis[i] < lis[j]+1:
					lis[i] = lis[j]+1
					if len_max < lis[i]:
						len_max = lis[i]
	print(len_max)
	print(lis)
	res = []
	for i in range(len_s):
		if lis[len_s-i-1] == len_max and len_max >= 2:
			res.append(s[len_s-i-1])
			print(s[len_s-i-1])
			len_max -= 1
	flag = 0
	for j in range(len_s-i+1):
		if flag ==1:
			res.pop()
		if s[j] < res[-1]:
			flag = 1
			res.append(s[j])
			print(res)

#求最大连续子序列和
def maxSum(s):
	len_s = len(s)
	maxsoft = -999999
	maxendingHere = 0
	for i in range(len_s):
		maxendingHere = maxendingHere+s[i] if maxendingHere+s[i] > s[i] else s[i]
		maxsoft = maxendingHere if maxendingHere > maxsoft else maxsoft
	print(maxsoft)
	return maxsoft
import math
#求最大连续子序列积
def maxMulti(s):
	len_s = len(s)
	s_log = []
	maxCur = 1.0
	minCur = 1.0
	maxTemp = 1.0
	minTemp = 1.0
	res = 1.0
	for i in range(len_s):
		maxTemp = max(maxCur*s[i], max(minCur*s[i], s[i]))
		minTemp = min(minCur*s[i], min(minCur*s[i], s[i]))
		minCur = minTemp
		maxCur = maxTemp
		res = max(res, maxCur)
	print(res)


if __name__ == '__main__':
	#print(findTheLongsetLine(18))
	#print(findCoin(15))
	print(upstair(4))
