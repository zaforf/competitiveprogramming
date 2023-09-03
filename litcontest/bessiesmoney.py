N = int(input())
cnts = [*map(int,input().split())]

dp = [[0 for i in range(7)] for i in range(N+1)] #sum, coins used
dp[0][0] = 1
for j in range(N+1):
	for k in range(7):
		used = [[False for i in range (7)] for i in range(N+1)]
		for i in range(len(cnts)):
			for x in range(cnts[i]):
				if j-(i+1)>=0 and k-1>=0 and not used[j-(i+1)][k-1]:
					dp[j][k]+=dp[j-(i+1)][k-1]
					used[j-(i+1)][k-1] = True
print(dp[N][-1])
