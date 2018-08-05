#find the right time 
import os
import sys

n = input()
n = int(n)
for i in range(n):
	times_in = input()
	times_temp = list(times_in)

	hh = int(times_in[:2])
	mm = int(times_in[3:5])
	ss = int(times_in[6:])
	if hh>=24:
		hh = hh%10
	if mm>=60:
		mm = mm%10
	if ss>=60:
		ss = ss%10
	print("%02d:%02d:%02d"%(hh,mm,ss))

	if times_temp[0] == '0' or times_temp[0] == '1' or (times_temp[0] == '2' and times_temp[1] <= '3'):
		pass
	else:
		times_temp[0] = 0 
	
	for j in range(2):
		if times_temp[j*3+3] > '5':
			times_temp[j*3+3] = 0

	res_tem = "".join(list(map(str,times_temp)))

	if i == n-1:
		print(res_tem, end='')
	else:
		print(res_tem)
