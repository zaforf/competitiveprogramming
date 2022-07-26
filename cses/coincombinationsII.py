read = open("cses/test.txt", "r").readline


n,d = map(int,read().split())
coins = list(map(int,read().split()))
ways = [[0 for i in range(d)] for i in range(n+1)]

for i in range(1,n+1):
    for i2 in range(d):
        if i>0: ways[i][i2] += ways[i-1][i2]
        if i2==coins[i-1]-1: ways[i][i2] += 1
        if i2>=coins[i-1]: ways[i][i2] += ways[i][i2-coins[i-1]]
        ways[i][i2] %= int(1e9+7)

print(ways[n][d-1])