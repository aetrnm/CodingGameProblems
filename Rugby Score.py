import math

score = int(input())

eps = 1e-6

for tries in range(math.floor(score/5) + 1):
    for kicks in range(tries + 1):
        penalties = (score - kicks*2 - tries*5)/3
        if (penalties >= 0 and penalties - int(penalties) < eps):
            print(f"{tries} {kicks} {int(penalties)}")
        elif (penalties < 0):
            break
