p = int(input())
adj = [[] for _ in range(p+1)]
for _ in range(p-1):
    a,b = map(int,input().split())
    adj[a].append(b)
    adj[b].append(a)
noded = -1
try:
    for _ in range(2):
        unvis = set(range(1,p+1))
        if noded != -1:
            unvis.remove(noded)
            search = [[noded,0]]
        else:
            search = [[unvis.pop(),0]]
        maxd = 0
        noded = 0
        while search:
            curr = search.pop()
            for nb in adj[curr[0]]:
                if nb in unvis:
                    search.append([nb,curr[1]+1])
                    unvis.remove(nb)
                    if curr[1]+1>maxd:
                        maxd=curr[1]+1
                        noded=nb
    print(maxd)
except KeyError:
    print(0)