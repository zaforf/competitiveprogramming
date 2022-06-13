#
#4 5
#.CGGC
#.CGCG
#CGCG.
#.CC.C
#

ty,tx = map(int,input().split())
grid = []
grass = []
ncow = 1
for _ in range(ty):
    grid.append([])
    for i,letter in enumerate(input()):
        if letter=="C":
            grid[_].append(ncow)
            ncow+=1
        elif letter=="G":
            grid[_].append(-1)
            grass.append([_,i])
        else:
            grid[_].append(0)
used = set()
ans = 0
for k in range(2,5):
    for m in range(len(grass)):
        y,x = grass[m]
        if y==-1:
            continue
        adj = set()
        if y>0 and grid[y-1][x]>0:
            adj.add(grid[y-1][x])
        if x>0 and grid[y][x-1]>0:
            adj.add(grid[y][x-1])
        if y<ty-1 and grid[y+1][x]>0:
            adj.add(grid[y+1][x])
        if x<tx-1 and grid[y][x+1]>0:
            adj.add(grid[y][x+1])
        if len(adj) < 2:
            grass[m][0]=-1
            continue
        if len(adj) != k:
            continue
        done = False
        for i in adj:
            if done:
                break
            for i2 in adj:
                if done:
                    break
                if i!=i2 and (i,i2) not in used and (i2,i) not in used:
                    ans += 1
                    used.add((i,i2))
                    done = True
        grass[m][0]=-1


print(ans)