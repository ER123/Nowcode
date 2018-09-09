#!/bin/python
# -*- coding: utf8 -*-
import sys
import os
import re

#请完成下面这个函数，实现题目要求的功能
#当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
#******************************开始写代码******************************


def  solve(S, T):
    lenS = len(S)
    lenT = len(T)
    if lenS < lenT:
        return 0
    count = 0
    for i in range(lenS - lenT + 1):#相同长度下进行相似匹配
        if change(S[i:lenT+i], T, lenT) == True:
            count += 1
    return count

def change(s, t, lenT):
    orderS = dict()
    orderT = dict()
    countS = 0
    countT = 0
    for i in range(lenT):
        if s[i] not in orderS and t[i] not in orderT:#同时不在字典内，添加入字典
            orderS[s[i]] = t[i]
            orderT[t[i]] = s[i]
        elif s[i] in orderS and t[i] in orderT and orderS[s[i]] == t[i] and orderT[t[i]] == s[i]:#在字典内比较对应的Key和Value
            continue
        else:
            return False
    print(orderS, orderT)
    return True


#******************************结束写代码******************************


try:
    _S = input()
except:
    _S = None

try:
    _T = input()
except:
    _T = None

  
res = solve(_S, _T)

print(str(res) + "\n")
