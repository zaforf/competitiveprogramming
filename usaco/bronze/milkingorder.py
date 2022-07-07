read = open("milkorder.in", "r").readline
write = open("milkorder.out", "w").write

n,l,s = map(int,read().split())
order = list(map(int,read().split()))
final = [0 for x in range(n)]
sett = {}
for _ in range(s):
    a,b = map(int,read().split())
    sett[a]=b-1
    final[b-1]=a
ok = False
p = l
for i in reversed(range(0,l)):
    if ok:
        if order[i] in sett:
            p=sett[order[i]]-1
        else:
            while final[p]!=0:
                p-=1
            final[p] = order[i]
    else:
        if order[i] in sett:
            ok = True
            p = sett[order[i]]-1
x = 0 
print(final)
for i in range(len(final)):
    if 1 in order:
        if final[i]==1:
            write(str(i+1))
            break
        else:
            if order[x]==1 and final[i]==0:
                write(str(i+1))
                break
            elif final[i]==order[x] or final[i]==0:
                x+=1
    else:
        if final[i]==0:
            write(str(i+1))
            break