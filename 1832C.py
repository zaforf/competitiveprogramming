for _ in range(int(input())):
	N = int(input())
	A = [*map(int,input().split())]
	ans = unique(A)
	for i in range(N-2):
		if A[i]<A[i+1] and A[i+1]<A[i+2]:
			ans-=1
		if A[i]>A[i+1] and A[i+1]>A[i+2]:
			ans-=1	
	print(ans)