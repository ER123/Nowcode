arr = [3,4,5,2,1,6,9,8]
length = len(arr)

def BubbleSort():
	for i in range(length):
		for j in range(i+1, length):
			if arr[j] < arr[i]:
				temp = arr[i]
				arr[i] = arr[j]
				arr[j] = temp
	print(arr)

def SelectSort():
	for i in range(length):
		index = i
		for j in range(i+1, length):
			if arr[j] < arr[index]:#找到最小的元素索引
				 index = j
		#交换，把无序区中最小的元素放到有序区最后
		temp = arr[i]
		arr[i] = arr[index]
		arr[index] = temp
	print(arr)

def InsertSort():
	for i in range(1, length-1):
		j = i+1
		while(j>=0 and i >=0):
			if arr[j] < arr[i]:
				temp = arr[i]
				arr[i] = arr[j]
				arr[j] = temp
			j -= 1
			i -= 1
	print(arr)

def partation(arr, left, right):
	pivot = left
	idx = pivot + 1
	for i in range(idx, right):
		if arr[i] < arr[pivot]:
			temp = arr[idx]
			arr[idx] = arr[i]
			arr[i] = temp
			idx += 1

	temp = arr[pivot]
	arr[pivot] = arr[idx-1]
	arr[idx-1] = temp

	return idx-1

def QuickSort(arr, left, right):
	if (left < right):
		partationIdx = partation(arr, left, right)
		QuickSort(arr, left, partationIdx-1)
		QuickSort(arr, partationIdx+1, right)
	#print(arr)

if __name__ == '__main__':
	#BubbleSort()
	#SelectSort()
	#InsertSort()
	QuickSort(arr, 0, length)
