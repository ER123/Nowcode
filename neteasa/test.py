s = input()

list1 = []

len1 = len(s)
print(len1)
s0 = s[0]
idx = 1
for i in range(1, len1):
	if s[i] == s0:
		idx += 1
		if i == len1-1:
			list1.append(idx)
	else:
		list1.append(idx)
		idx = 1
		if i == len1-1:
			list1.append(1)
		else:
			s0 = s[i+1]
print(list1)
len2 = len(list1)
count = 0
for i in range(len(list1)):
	count += list1[i]
print(count/len2)
