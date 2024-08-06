def solve():
    n,m = map(int,input().split())
    g = [input() for i in range(n)]
    tot = sum([row.count("#") for row in g])
    cnt = 0
    for i in range(n):
        for j in range(m):
            if g[i][j]=="#":
                cnt += 1
            if (cnt==(tot+1)//2):
                print(i+1,j+1)
                return

for _ in range(int(input())):
    solve()