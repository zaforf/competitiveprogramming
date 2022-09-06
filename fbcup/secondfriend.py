read = open("sfriend.in", "r").readline
write = open("sfriend.out", "w").write

t = int(read())
for i in range(t):
    y,x = map(int,read().split())
    grid = []
    cnt = 0
    for l in range(y):
        grid.append(read())
        cnt+=grid[l].count('^')

    if (y<3 or x<3) and cnt!=0:
        write("Case #"+str(i+1)+": Impossible\n")
    elif cnt==0:
        write("Case #"+str(i+1)+": Possible\n")
        for l in range(y):
            write("."*x)
            write("\n")
    else:
        write("Case #"+str(i+1)+": Possible\n")
        for l in range(y):
            write("^"*x)
            write("\n")