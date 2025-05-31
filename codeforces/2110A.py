for _ in range(int(input())):
	n = int(input())
	a = [*map(int,input().split())]
	a.sort()
	ans = 10000000
	for i in range(n):
		for j in range(n):
			if (a[i]+a[j]) % 2 == 0:
				ans = min(ans, i + (n-j-1))
	print(ans)