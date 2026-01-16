s = input()
nums = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
n = len(s)
dp = [[0,0] for _ in range(n)]

for i in range(n):
	before = 0 if i == 0 else dp[i-1][0]
	cnt = 1 if i == 0 else dp[i-1][1]
	if before > dp[i][0]:
		dp[i] = [before, cnt]
	elif before == dp[i][0]:
		dp[i][1] = (dp[i][1] + cnt) % 9302023

	for j in range(10):
		word = nums[j]
		m = len(word)
		if i + m > n:
			continue
		if s[i:i+m] == word:
			saved = before + m - 1
			if saved > dp[i+m-1][0]:
				dp[i+m-1] = [saved, cnt]
			elif saved == dp[i+m-1][0]:
				dp[i+m-1][1] = (dp[i+m-1][1] + cnt) % 9302023

print(n-dp[n-1][0])
print(dp[n-1][1] % 9202023)
