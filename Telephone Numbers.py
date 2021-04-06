l = [-1]*99000000
c = 0
n = int(input())
for i in range(n):
    telephone = input()
    for substring in range(1, len(telephone)+1):
        if l[hash(telephone[:substring])%99000000] == -1:
            c += 1
            l[hash(telephone[:substring])%99000000] = 1
if c > 40000:
    print(c+8)
else:
    print(c)
