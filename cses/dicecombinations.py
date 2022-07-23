from math import inf

dice = [i for i in range(1,7)]
N = int(input())
poss = [0 for i in range(N+1)]
poss[0] = 1

for i in range(N+1):
    for d in dice:
        if i-d>=0:
            poss[i] += poss[i-d]
            poss[i] %= int(1e9+7)

print(poss[-1])