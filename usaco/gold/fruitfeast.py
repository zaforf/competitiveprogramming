read = open("feast.in", "r").readline
write = open("feast.out", "w").write

t,a,b = map(int,read().split())
poss = [False for i in range(t+1)]
poss[a] = True
poss[b] = True
for i in range(1,len(poss)):
    if poss[i]:
        if i+a<len(poss): poss[i+a] = True
        if i+b<len(poss): poss[i+b] = True
for i in range(1,len(poss)):
    if poss[i]: poss[i//2] = True
for i in range(1,len(poss)):
    if poss[i]:
        if i+a<len(poss): poss[i+a] = True
        if i+b<len(poss): poss[i+b] = True
for i in reversed(range(1,t+1)):
    if poss[i]:
        write(str(i))
        break