import sys
f = int(input())
n = int(input())

if(n == 1):
    print(f)
    sys.exit()

line = []
line.append(1)
line.append(f)

for i in range(n-2):
    tempList = []
    curNum = line[0]
    counter = 0
    for j in range(len(line)):
        if(line[j] != curNum):
            tempList.append(counter)
            tempList.append(curNum)
            curNum = line[j]
            counter = 1
        else:
            counter += 1
    tempList.append(counter)
    tempList.append(curNum)
    line = tempList.copy()

print(' '.join([str(i) for i in tempList]))
