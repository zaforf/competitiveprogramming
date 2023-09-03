import sys
sys.stdin = open("swap.in", "r")
sys.stdout = open("swap.out", "w")

N,M,K = map(int,input().split())
l = [*range(1,N+1)]

for i in range(M):
	a,b = map(int,input().split())
	a-=1
	l = l[:a]+l[b-1:a-1 if a>0 else None:-1]+l[min(len(l),b):]

ans = [*range(1,N+1)]
def apply(li,dif):
	k = [0 for i in li]
	for i in range(len(li)):
		k[i] = li[dif[i]-1]
	return k

x = 1
while K>0:
	if K&x:
		ans = apply(ans,l)
		K-=x
	x*=2
	l = apply(l,l)
print("\n".join(map(str,ans)))