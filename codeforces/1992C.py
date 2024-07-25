T = int(input())

for _ in range(T):
	a,m,k = map(int,input().split())
	x = [*range(a,m,-1)]
	x.extend([*range(1,m+1)])
	print(" ".join(map(str,x)))