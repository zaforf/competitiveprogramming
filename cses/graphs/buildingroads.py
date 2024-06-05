 
n,m = map(int,input().split())
adj = [set() for _ in range(n+1)]
for _ in range(m):
    a,b = map(int,input().split())
    adj[a].add(b)
    adj[b].add(a)
heads = set()
unvisited = set(range(1,n+1))
while unvisited:
    head = unvisited.pop()
    heads.add(head)
    comp = [head]
    while comp:
        now = comp.pop()
        for curr in adj[now]:
            if curr in unvisited:
                unvisited.remove(curr)
                comp.append(curr)
 
print(len(heads)-1)
thing = heads.pop()
for other in heads:
    print(thing,other)