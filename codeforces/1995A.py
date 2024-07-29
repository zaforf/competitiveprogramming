for _ in range(int(input())):
	n, k = map(int,input().split())
	a = list(range(1,n+1))+list(range(1,n))
	a.sort(reverse=True)
	ans = 0
	for i in range(len(a)):
		if k<=0: break
		k -= a[i]
		ans += 1
	print(ans)