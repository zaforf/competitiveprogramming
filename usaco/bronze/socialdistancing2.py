read = open("socdist2.in", "r").readline
write = open("socdist2.out", "w").write

from math import inf
n = int(read())
cows = [list(map(int,read().split())) for i in range(n)]
cows.sort()
r = inf
for i in range(1,n):
    if cows[i][1]^cows[i-1][1]==True:
        r = min(cows[i][0]-cows[i-1][0],r)
ans = 0
for i in range(n):
    if cows[i][1]==0:
        continue
    if i==0 or cows[i][0]-cows[i-1][0]>=r or cows[i-1][0]==0:
        ans+=1
write(str(ans))