maxSpeed = int(input())
numOfLights = int(input())
lights = []
eps = 1e-6
for i in range(numOfLights):
    lights.append(tuple(int(j) for j in input().split()))

for speed in range(maxSpeed, 0,-1):
    for light in lights:
        changeFreq = speed/3.6 * light[1]
        if (light[0] + eps)//changeFreq % 2 != 0:
            break
    else:
        print(speed)
        break
