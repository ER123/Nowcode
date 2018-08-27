import os

def findSubStr(str, substr1, substr2):
	if str == "":
		return False
	else:
		idx1 = str.find(substr1)
		if idx1 == -1:
			return False
		idx2 = str.find(substr2, idx1 + len(substr1))
		if idx2 == -1:
			return False 
	return True 

def main():
	str = input()
	substr1 = input()
	substr2 = input()
	res1 = findSubStr(str, substr1, substr2)
	res2 = findSubStr(str[::-1], substr1, substr2)
	if res1 and res2:
		print("both")
	elif res1:
		print("forward")
	elif res2:
		print("backward")
	else:
		print("invaild")

import math

def calCoord():
	line = raw_input()
	L_R = line.split(" ")
	L = float(L_R[0])
	R = float(L_R[1])
	L0 = 2*math.pi*R
	L1 = L0/2
	L2 = L0/4
	L = L%L0
	sita = L/R
	y = R*math.sin(sita)
	x = R*math.cos(sita)
	print("%.3f %.3f"%(x,-y))
	print("%.3f %.3f"%(x,y))

def allMethods():
	n = int(input())
	balls = raw_input()
	#print(balls)
	ball = balls.split(" ")
	#print(ball)
	res = [0]*(n+1)
	res[0] = 1
	for i in range(1,len(ball)+1):
		temp = []
		j = i-1
		while j>=0 and (ball[j] not in temp):
			temp.append(ball[j])
			res[i] += res[j]
			res[i] = int(res[i]%(math.pow(10,9)+7))
			j -= 1
	print(res[len(ball)])

if __name__ == '__main__':
	#main()
	#calCoord()
	allMethods()
