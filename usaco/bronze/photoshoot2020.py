read = open("photo.in", "r").readline
write = open("photo.out", "w").write

n = int(read())
sums = list(map(int,read().split()))
a = set(range(1,n+1))
ans = list()

for i in range(1,n+1):
    a = set(range(1,n+1))
    ans.clear()
    ans.append(i)
    a.remove(i)
    ok = False
    for x in sums:
        if x-i in a:
            ans.append(x-i)
            i = x-i
            a.remove(i)
        else:
            ok = True
            break
    if ok:
        continue
    else:
        write(" ".join([str(x) for x in ans]))
        break
        

