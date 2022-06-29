read = open("guess.in", "r").readline
write = open("guess.out", "w").write

n = int(read())
anms = []
for _ in range(n):
    anms.append(set(read().split()[2:]))
ans = 0
for anm in anms:
    for anm2 in anms:
        if anm2 == anm:
            continue
        ret = 0
        for char in anm:
            if char in anm2:
                ret+=1
        ans = max(ans,ret)
write(str(ans+1))