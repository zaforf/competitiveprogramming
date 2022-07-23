import sys
read = sys.stdin.readline

n = int(read())
grid = [read() for i in range(n)]
paths = [[0 for i in range(n)]for i in range(n)]

for i in range(n):
    for i2 in range(n):
        if grid[i][i2] == "*": continue
        if i==i2 and i==0:
            paths[i][i2] = 1
            continue
        if i2 != 0: paths[i][i2] += paths[i][i2-1] % int(1e9+7)
        paths[i][i2] += paths[i-1][i2] % int(1e9+7)
        paths[i][i2] %= int(1e9+7)

print(paths[n-1][n-1])