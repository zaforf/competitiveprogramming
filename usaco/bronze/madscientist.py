read = open("breedflip.in", "r").readline
write = open("breedflip.out", "w").write

n = int(read())
a = read().strip()
b = read().strip()
ans = 0
prevchange = False
for i in range(n):
    if b[i]!=a[i]:
        if prevchange:
            continue
        else:
            ans+=1
            prevchange = True
    else:
        prevchange = False
write(str(ans))