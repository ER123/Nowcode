import os

T = int(input())

for i in range(T):

	N = int(input())

	talk = input()
	talk = talk.strip().split(" ") 

	res = []
	num_id = 0
	for id in talk:
		if id in res:
			res.remove(id)
			res.append(id)
		else:			
			res.append(id)
			num_id += 1

	res.reverse()

	for k in range(num_id):
		if k != num_id-1:
			print(res[k], end=" ")
		else:
			print(res[k], end="\n")
