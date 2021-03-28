n = int(input())

for x in range(n+1, 2*n + 1):
    if (n*x) % (x-n) == 0:
        y = int((n * x) / (x - n))
        print(f"1/{n} = 1/{y} + 1/{x}")
