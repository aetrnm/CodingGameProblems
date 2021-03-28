import sys
import math

def findAns(a):
    curRatio = a
    i = 2
    while(True):
        curRatio *= a
        curRatio /= i
        if(curRatio < 1):
            return i
        i += 1

ans = []
k = int(input())
for i in input().split():
    a = float(i)
    ans.append(findAns(a))

print(*ans, sep = " ")

# 3/5 tests
