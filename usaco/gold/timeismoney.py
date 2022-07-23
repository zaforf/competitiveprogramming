from math import inf

read = open("time.in", "r").readline
write = open("time.out", "w").write

n,m,p = map(int,read().split())
mons = [0] + list(map(int,read().split()))
adj = [set() for i in range(n+1)]
for i in range(m):
    a,b = map(int,read().split())
    adj[a].add(b)
e = max(mons)

best = [[-inf for i in range(n+1)] for i in range(e+1)]
best[0][1] = 0

for d in range(e):
    for c in range(n+1):
        if abs(best[d][c]) is inf:
            continue
        else:
            for nb in adj[c]:
                if d<e:
                    best[d+1][nb] = max(best[d+1][nb],best[d][c]+mons[nb]-p*(2*d+1))
    if best[d][1] < -1000 and best[d][1] != -inf:
        print(best[d][1])
        break

ans = best[0][1]
for k in best:
    ans = max(ans,k[1])
write(str(ans))