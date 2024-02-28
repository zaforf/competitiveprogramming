input()
c = [*map(int,input().split())]
dp = [0 for i in range(sum(c)+1)]
tot = sum(c)
dp[tot]=True

for coin in c:
	for i in range(len(dp)):
		if i+coin<len(dp) and dp[i+coin]:
			dp[i]=True

print(sum(dp)-1)
for i in range(1,len(dp)):
	if dp[i]:
		print(i,end=" ")