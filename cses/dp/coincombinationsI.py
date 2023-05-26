
n,d = map(int,input().split())
coins = list(map(int,input().split()))

ways = [0 for i in range(d+1)]
ways[0] = 1

for i in range(0,d+1):
    if ways[i] == 0:
        continue
    for c in coins:
        if i+c<d+1:
            ways[i+c] += ways[i]
            ways[i+c] %= int(1e9+7)

print(ways[-1])