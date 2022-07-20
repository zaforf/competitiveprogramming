read = open("measurement.in", "r").readline
write = open("measurement.out", "w").write

n,g = map(int,read().split())
curr = {0:g}
ments = []
for i in range(n):
    ments.append(list(map(int,read().split())))
ments.sort()
maxmilk = g
lastdisplay = set([0])
currdisplay = set()
ans = 0
print(ments)
for ment in ments:
    if ment[1] in curr:
        curr[ment[1]] += ment[2]
    else:
        curr[ment[1]] = g+ment[2]
    maxmilk = max(curr.values())
    currdisplay.clear()
    for k in curr:
        if curr[k] == maxmilk:
            currdisplay.add(k)
    if currdisplay != lastdisplay:
        ans += 1
    print(curr,maxmilk,lastdisplay,currdisplay)
    lastdisplay = set(list(currdisplay))
write(str(ans))