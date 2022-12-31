read = open("badmilk.in", "r").readline
write = open("badmilk.out", "w").write




N,M,D,S = map(int,read().split())
totaldrinks = {i:0 for i in range(1,M+1)}
sickdrinks = {i:0 for i in range(1,M+1)}
drinks = []
for i in range(D):
    drinks.append(list(map(int,read().split())))
sicktime = [0 for i in range(N+1)]
for i in range(S):
    a,b = map(int,read().split())
    sicktime[a] = b
# d[0] is person, d[1] is what drink, d[2] is what time
drinks.sort()
sicks = set()
totals = set()
for i in range(len(drinks)):
    if i>0 and drinks[i][0]!=drinks[i-1][0]:
        for t in sicks:
            sickdrinks[t]+=1
        for t in totals:
            totaldrinks[t]+=1
        sicks = set()
        totals = set()
    if drinks[i][2]<sicktime[drinks[i][0]]:
        sicks.add(drinks[i][1])
    totals.add(drinks[i][1])
for t in sicks:
    sickdrinks[t]+=1
for t in totals:
    totaldrinks[t]+=1
ans = 0
for i in sickdrinks:
    if sickdrinks[i]==S:
        ans = max(ans,totaldrinks[i])
write(str(ans))