for _ in range(int(input())):
	N = int(input())
	A = [*map(int,input().split())]
	ind = [-1 for i in range(N+1)]
	dp = [0 for i in range(N)]
	for i in range(N):
		if i==0: ind[A[i]]=i;continue;
		dp[i]=dp[i-1]
		if ind[A[i]]==-1: ind[A[i]]=i;continue;
		dp[i] = max(dp[i],dp[max(ind[A[i]]-1,0)]+i-ind[A[i]]+1)
		if (dp[i-1]-(dp[max(ind[A[i]]-1,0)]+i-ind[A[i]]+1)>=0):
			ind[A[i]]=i
	print(dp[-1])