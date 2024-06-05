

n,m = map(int,input().split())
adj = [set() for _ in range(n+1)]
for _ in range(m):
    a,b = map(int,input().split())
    adj[a].add(b)
    adj[b].add(a)
red = set()
blue = set()
unvis = set(range(1,n+1))
while unvis:
    search = [unvis.pop()]
    red.add(search[-1])
    while search:
        curr = search.pop()
        for nb in adj[curr]:
            if curr in red:
                blue.add(nb)
            else:
                red.add(nb)
            if nb in unvis:
                search.append(nb)
                unvis.remove(nb)

def solve():
    for x in range(1,n+1):
        if x in red and x in blue:
            print("IMPOSSIBLE")
            return 0
    for x in range(1,n+1):
        if x in red:
            print(1,end=" ")
        elif x in blue:
            print(2,end=" ")
        else:
            print("n",end=" ")
        
solve()
