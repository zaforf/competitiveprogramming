for _ in range(int(input())):
	n = int(input())
	a = [*map(int, input().split())]
	mx = max(a)
	ind_mx = a.index(mx)
	if a.count(mx) == n:
		print("NO")
		continue
	print("YES")
	ans = [1 for _ in range(n)]
	ans[ind_mx] = 2
	print(*ans)