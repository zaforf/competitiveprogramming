MOD = 1_000_000_007
dp = [[0,0] for i in range(int(1e6)+1)]
dp[1][0]=1 # split top
dp[1][1]=1 # joined top
for i in range(2,len(dp)):
	dp[i][0] = (dp[i-1][0]*4 + dp[i-1][1])%MOD
	dp[i][1] = (dp[i-1][0] + dp[i-1][1]*2)%MOD

for _ in range(int(input())):
	n=int(input())
	print((dp[n][0]+dp[n][1])%MOD)