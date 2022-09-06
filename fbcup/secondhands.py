
read = open("shands.in", "r").readline
write = open("shands.out", "w").write

t = int(read())
for x in range(t):
    n,e = map(int,read().split())
    cnt = {}
    for i in list(map(int,read().split())):
        if i not in cnt:
            cnt[i]=0
        cnt[i]+=1
    ok = True
    for k in cnt:
        if cnt[k]>2:
            ok = False
    if not ok or n>2*e:
        write("Case #"+str(x+1)+": NO\n")
    else:
        write("Case #"+str(x+1)+": YES\n")
        