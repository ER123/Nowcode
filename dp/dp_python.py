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

def LCS(len1, len2):
	if len1 == 0 or len2 == 0:
		return 0
	res = 
	len1 = len(str1)
	len2 = len(str2)
	for i in range(min())


if __name__ == '__main__':
	#print(findTheLongsetLine(18))
	#print(findCoin(15))
	print(upstair(4))
