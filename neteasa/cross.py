import os

a = input()
b = input()
c = input()
d = input()

list1_start = min(int(a), int(b))
list1_end = max(int(a), int(b))+1

list2_start = min(int(c), int(d))
list2_end = max(int(c), int(d))+1

list1 = list(range(list1_start, list1_end))
list2 = list(range(list2_start, list2_end))

if list1_end < list2_start:
	print ("None")
elif (list1_start < list2_start) and (list1_end > list2_end):
	res = list2
	print(res)
elif list1_start > list2_start and list1_end < list2_end:
	res = list1
	print(res)
elif list1_start > list2_start:
	res = list(range(list1_start, list2_end))
	print(res)
else:
	res = list(range(list2_start, list1_end))
	print(res)
