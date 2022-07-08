read = open("maxcross.in", "r").readline
write = open("maxcross.out", "w").write

from math import inf
n,k,b = map(int,read().split())
broke = [False for i in range(n+1)]
for _ in range(b):
    broke[int(read().strip())]=True
p = [0]
for i in range(1,len(broke)):
    p.append(p[-1]+(1 if broke[i] else 0))
ans = inf
print(p)
for i in range(k,n+1):
    ans = min(ans,p[i]-p[i-k])
write(str(ans))