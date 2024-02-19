N = int(input())
weights = [0]+[*map(int,input().split())]
adj = [[] for i in range(N+1)]
vis = [False for i in range(N+1)]

for i in range(N-1):
	a,b = map(int,input().split())
	adj[a].append(b)
	adj[b].append(a)

ans = 0
def findans(i): # return weight, added
	vis[i]=True
	ans,z=0,0
	subtrees = []
	for nb in adj[i]:
		if not vis[nb]:
			w,inc = findans(nb)
			z+=inc
			subtrees.append(w)
	if subtrees:
		ans += len(subtrees)*max(subtrees)-sum(subtrees)
	return weights[i]+sum(subtrees)+ans,ans+z
print(findans(1)[1])

