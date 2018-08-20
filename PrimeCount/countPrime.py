n = int(input())
isprime = [1] * (n+1)
num = [0] * (n+1)
isprime[0] = 0
isprime[1] = 0

#1.埃氏素数计数法，一个合数可以分解为若干素数的乘积，如果一个数是素数那么这个数的倍数都不是素数，
#因此可以先排除这些数，如果一个数不是素数那么不跳过素数量不变，算法时间复杂度O(nloglogn)
for i in range(2, n+1):
	if(isprime[i]):
		num[i] = num[i-1]+1
		j = i*2
		while(j<=n):
			isprime[j] = 0
			j += i
	else:
		num[i] = num[i-1]
print(num)
print(isprime)

prime = [1] * (n+1)
vis = [0] * (n+1)
count = 0
#2.欧拉计数法：埃氏计数法有重复，如6既是2的倍数又是3的倍数，
for i in range(2, n+1):
	if vis[i] == 0:     #如果一个数是素数找出来，素数数量count加1
		prime[count] = i
		count += 1
	for j in range(1,count+1):
		if i*prime[j] > n:
			break
		vis[i * prime[j]] = 1 #标记合数
		if i % prime[j] == 0: #如果一个数是合数那么它在之前已经被标记过
			break
print(count)
print(vis)
print(prime[:count])
