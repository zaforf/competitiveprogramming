x = int(input())
for _ in range(x):
    n = int(input())
    adj = [set() for _ in range(n+1)]
    for _ in range(n-1):
        a,b = map(int,input().split())
        adj[a].add(b)
    dict = {}
    def count(x):
        r = 0
        if x in dict:
            return dict[x]
        for nb in adj[x]:
            r += count(nb)
            r += 1
        dict[x] = r
        return r
    count(1)
    root = 1
    saved = 0
    ok = True
    while ok:
        max = -1
        maxn = 0
        for nb in adj[root]:
            if dict[nb]>max:
                max=dict[nb]
                maxn=nb
        adj[root].remove(maxn)
        saved+=max
        if len(adj[root])>0:
            root=adj[root].pop()
        else:
            ok = False
        if len(adj[root])==0:
            ok = False
    print(saved)    