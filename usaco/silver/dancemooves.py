N,K = map(int,input().split())

vis = [set([i]) for i in range(N)]
seq = [*range(N)]


for i in range(K):
	a,b = map(int,input().split())
	a-=1
	b-=1
	vis[seq[a]].add(b)
	vis[seq[b]].add(a)
	t=seq[a]
	seq[a]=seq[b]
	seq[b]=t

ans = [0 for i in range(N)]
for i in range(N):
	if ans[i]!=0: continue
	z = vis[i]
	p = seq[i]
	while p!=i:
		z.update(vis[p])
		p = seq[p]
	ans[i] = len(z)
	p = seq[i]
	while p!=i:
		ans[p]=len(z)
		p = seq[p]

print("\n".join(map(str,ans)))
