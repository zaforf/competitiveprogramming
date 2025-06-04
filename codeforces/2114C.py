for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	ans = 1
	j = 0
	for i in range(1,n):
		if a[i] > a[j] + 1:
			ans += 1
			j = i
	print(ans)