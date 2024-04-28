def query(n,k):
	if n==1: return 1
	if k<=(n+1)//2:
		if 2*k>n: return 2*k%n
		else: return 2*k
	if n&1:
		return 2*query(n//2,k-(n+1)//2)+1
	else:
		return 2*query(n//2,k-(n+1)//2)-1

for _ in range(int(input())):
	n,k = map(int,input().split())
	print(query(n,k))