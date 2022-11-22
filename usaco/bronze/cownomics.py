read = open("cownomics.in", "r").readline
write = open("cownomics.out", "w").write

n, length = map(int,read().split())

spot = []
pln = []

for i in range(n):
    spot.append(read())
for i in range(n):
    pln.append(read())
ans = 0
for j in range(length):    
    acgt = [0,0,0,0]  
    e = "ACGT"
    for i in range(n):
        acgt[e.index(spot[i][j])] += 1
    ok = True
    for i in range(n):
        if acgt[e.index(pln[i][j])] != 0:
            ok = False
    if ok:
        ans +=1
write(str(ans))