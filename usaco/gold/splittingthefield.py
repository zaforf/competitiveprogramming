from math import inf
read = open("split.in", "r").readline
write = open("split.out", "w").write

n = int(read())
pts,xs,ys = [],[],[]
for i in range(n):
    a,b = map(int,read().split())
    xs.append([a,b])
    ys.append([b,a])
xs.sort()
ys.sort()
tot = (xs[-1][0]-xs[0][0])*(ys[-1][0]-ys[0][0])
ans = inf
miny,maxy = xs[-1][1],xs[-1][1]
minx,maxx = ys[-1][1],ys[-1][1]
for i in reversed(range(1,n)):
    miny = min(miny,xs[i][1])
    maxy = max(maxy,xs[i][1])
    minx = min(minx,ys[i][1])
    maxx = max(maxx,ys[i][1])
    xs[i].append(miny)
    xs[i].append(maxy)
    ys[i].append(minx)
    ys[i].append(maxx)
miny,maxy = xs[0][1],xs[0][1]
for i in range(1,n):
    miny = min(miny,xs[i-1][1])
    maxy = max(maxy,xs[i-1][1])
    if xs[i][0]==xs[i-1][0]: continue
    curr = (xs[i-1][0]-xs[0][0])*(maxy-miny)
    aft = (xs[-1][0]-xs[i][0])*(xs[i][3]-xs[i][2])
    ans = min(ans,curr+aft)
minx,maxx = ys[0][1],ys[0][1]
for i in range(1,n):
    minx = min(minx,ys[i-1][1])
    maxx = max(maxx,ys[i-1][1])
    if ys[i][0]==ys[i-1][0]: continue
    curr = (ys[i-1][0]-ys[0][0])*(maxx-minx)
    aft = (ys[-1][0]-ys[i][0])*(ys[i][3]-ys[i][2])
    ans = min(ans,curr+aft)
write(str(tot-ans))