for _ in range(int(input())):
	N,K = map(int,input().split())
	A = list(zip(map(int,input().split()),[i for i in range(N)]))
	B = list(map(int,input().split()))
	A.sort()
	B.sort()
	ans = [0 for i in range(N)]
	for i in range(N):
		ans[A[i][1]]=B[i]
	print(*ans)