for _ in range(int(input())):
	N,M = map(int,input().split())
	adj = [[] for i in range(N+1)]
	for _ in range(M):
		a,b = map(int,input().split())
		adj[a].append(b)
		adj[b].append(a)
	ans = []
	for i in range(1,N+1):
		ans.append(len(adj[i]))
	c = set(ans)
	c = [i for i in c]
	c.remove(1)
	if ans.count(c[0])==1 or len(c)==1:
		print(c[0],c[len(c)-1]-1)
	else:
		print(c[1],c[0]-1)
