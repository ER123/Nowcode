import os
import re

def findSub(str, sub):
	reg = re.compile("(?="+sub+")")
	length = len(reg.findall(str))
	return length


T = int(input())
for i in range(T):
	row_col = input()
	row_col = row_col.strip().split(" ")
	row = int(row_col[0])
	col = int(row_col[1])
	worldMat = []
	count_world = 0
	for j in range(row):
		worldRow = input()
		worldMat.append(worldRow)

	world = input()

	#每一行含有指定单词数
	for j in range(row):
		count_world += findSub(worldMat[j], world)

	#首先把每一列转为字符串，再计算字符串中含有指定单词数
	for j in range(col):
		worldCol = []
		for k in range(row):
			worldCol.append(worldMat[k][j])
		worldCol_temp = "".join(list(map(str,worldCol)))
		count_world += findSub(worldCol_temp, world)

	#求对角含有指定单词个数
	if col >= row:
		for j in range(col):
			worldDiag = []
			for k in range(row):
				if (k+j) < col:
					worldDiag.append(worldMat[k][k+j])
			worldDiag_temp = "".join(list(map(str,worldDiag)))
			count_world += findSub(worldDiag_temp, world)

		for j in range(1,row):
			worldDiag = []
			for k in range(row-j):
				if k+j < row:
					worldDiag.append(worldMat[k+j][k])
			worldDiag_temp = "".join(list(map(str,worldDiag)))
			count_world += findSub(worldDiag_temp, world)

	else:
		for j in range(row):
			worldDiag = []
			for k in range(col):
				if (k+j) < row:
					worldDiag.append(worldMat[k+j][k])
			worldDiag_temp = "".join(list(map(str,worldDiag)))
			count_world += findSub(worldDiag_temp, world)

		for j in range(1,col):
			worldDiag = []
			for k in range(col-j):
				if k+j < col:
					worldDiag.append(worldMat[k][k+j])
			worldDiag_temp = "".join(list(map(str,worldDiag)))
			count_world += findSub(worldDiag_temp, world)

	print(count_world)