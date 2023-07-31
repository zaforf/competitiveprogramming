N,X = map(int,input().split())
M = [*map(int,input().split())]

def sumupto(n): return n*(n+1)//2

l=N-1
c,csum,ans = 0,0,0
for r in range(N-1,-1,-1):
	l = min(l,r)
	while c+M[l]<X:
		c+=M[l]
		csum+=sumupto(M[l])
		l-=1
	csum+=sumupto(M[l])-sumupto(M[l]-(X-c))
	ans = max(ans,csum)
	csum-=sumupto(M[l])-sumupto(M[l]-(X-c))
	c=max(0,c-M[r])
	csum=max(0,csum-sumupto(M[r]))
print(ans)