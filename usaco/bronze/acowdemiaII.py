
lines, nnames = map(int,input().split())
namelist = {}
n = 0
for name in input().split():
    namelist[name] = n
    n+=1
grid = [["?" for _ in range(nnames)] for _ in range(nnames)]
for nline in range(lines):
    inp = input().split()
    lastmax = inp[0]
    checked = []
    brk = len(inp)
    for i in range(len(inp)):
        if inp[i]<lastmax or brk!=len(inp):
            if inp[i-1]>inp[i]:
                    brk = i
            for obj in checked[:brk]:
                grid[namelist[inp[i]]][namelist[obj]]=1
                grid[namelist[obj]][namelist[inp[i]]]=0
        checked.append(inp[i])
        lastmax = max(lastmax,inp[i])

for i in range(len(grid)):
    for i2 in range(len(grid[i])):
        if i==i2:
            print("B",end="")
        else:
            print(grid[i][i2],end="")
    print()