import sys
sys.setrecursionlimit(int(1e9))

T = int(input())

def dfs(i,c):
	if par[i]!=-1: return
	t = []
	par[i] = c
	for nb in adj[i]:
		if par[nb]==-1:
			dfs(nb,c)

def findMin(a,b):
	ret = float('inf')
	ax,bx = 0,0
	while ax<len(a) and bx<len(b):
		ret = min(ret,abs(b[bx]-a[ax]))
		if  a[ax]<b[bx]:
			ax+=1
		else:
			bx+=1
	return ret**2

for i in range(T):
	N,M = map(int,input().split())
	adj = [set() for i in range(N+1)]
	for j in range(M):
		a,b = map(int,input().split())
		adj[a].add(b)
		adj[b].add(a)
	par = [-1 for i in range(N+1)]
	cmps = 0
	dfs(1,cmps)
	cmps += 1
	dfs(N,cmps)
	cmps += 1
	for i in range(1,N):
		if par[i]==-1:
			dfs(i,cmps)
			cmps += 1
	dist = [[float('inf'),float('inf')] for i in range(cmps)]
	if par[N]==0 or par[0]==1:
		print(0)
		continue
	last0 = float('inf')
	last1 = float('inf')
	for i in range(1,N+1):
		if par[i]==0:
			last0 = i
		elif par[i]==1:
			last1 = i
		if last0 != float('inf'):
			dist[par[i]][0] = min(dist[par[i]][0],i-last0)
		if last1 != float('inf'):
			dist[par[i]][1] = min(dist[par[i]][1],i-last1)
	last0 = float('inf')
	last1 = float('inf')
	for i in range(N,0,-1):
		if par[i]==1:
			last1 = i
		elif par[i]==0:
			last0 = i
		if last1 != float('inf'):
			dist[par[i]][1] = min(dist[par[i]][1],last1-i)
		if last0 != float('inf'):
			dist[par[i]][0] = min(dist[par[i]][0],last0-i)
	ans = dist[0][1]**2
	ans = min(ans,dist[1][0])**2
	for i in range(2,cmps):
		ans = min(ans,dist[i][0]**2+dist[i][1]**2)
	# print(par)
	# print(dist)
	print(ans)

