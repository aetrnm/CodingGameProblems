from numpy import *

f = int(input())
n = int(input())

prevLine = []
prevLine.append(1)
prevLine.append(f)
nextLine = []

def findSeqFromIndexJ(j):
    counter = 0
    numToCount = prevLine[j]
    for i in range(j,len(prevLine)):
        if(prevLine[i] == numToCount):
            counter += 1
        else:
            break
    return (counter, numToCount)

for i in range(n):
    nextLine = []
    print(prevLine)
    for j in range(len(prevLine)):
        (amountOfNum, num) = findSeqFromIndexJ(j)
        nextLine.append(amountOfNum)
        nextLine.append(num)
        j += amountOfNum
    prevLine = nextLine.copy()
    del nextLine[:]
    print("Cycle number " + str(i) + " finished")

print(prevLine)
