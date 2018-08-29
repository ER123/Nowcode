import sys
string = sys.stdin.readline().strip()
def sum(s):
    sum = 0
    for i in s:
        sum += int(i)
    return sum
count = [0] * (len(string) + 1)
temp = ''
for i, s in enumerate(string):

    if (sum(temp+s)%3 == 0 or sum(s) %3 == 0):
        temp = ''
        count[i] = 1 + count[i - 1]
    else:
        count[i] = count[i-1]
        temp += s

print count[len(string) - 1]
