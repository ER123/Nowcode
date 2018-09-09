#根据unicode编码格式求给定字符串是否是合法的unicode字符
def valid():
    N = int(input())
    code = list(map(int, input().split(" ")))
    count = 0
    for i in range(N):
        if count == 0:
            if code[i] & 0x80 == 0:
                count = 0
            elif (code[i] & 0xe0) == 0xc0:
                count = 1
            elif (code[i] & 0xf0) == 0xe0:
                count = 2
            elif (code[i] & 0xf8) == 0xf0:
                count == 3
            else:
                print(0)
                return ""
        else:
            if (code[i] & 0xc0) != 0x80:
                print(0)
                return ""
            count -= 1

    if count == 0:
        print(1)
        return ""
    else:
        print(0)
        return ""

if __name__ == '__main__':
    valid()
