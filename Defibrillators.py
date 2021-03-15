import math

def getFloatByString(string):
    parts = string.split(",")
    return float(parts[0] + "." + parts[1])

lonStart = getFloatByString(input())
latStart = getFloatByString(input())
numOfDefibrilators = int(input())

minDistance = 1e9
nameOfNearestDef = ""

for i in range(numOfDefibrilators):
    defibInfo = input()
    details = defibInfo.split(";")
    name = details[1]
    lonCur = getFloatByString(details[4])
    latCur = getFloatByString(details[5])
    
    curX = (lonCur - lonStart) * math.cos((latStart + latCur)/2)
    curY = (latCur - latStart)

    curDistance = math.sqrt(curX ** 2 + curY ** 2) * 6371

    if (curDistance < minDistance):
        minDistance = curDistance
        nameOfNearestDef = name

print(nameOfNearestDef)
