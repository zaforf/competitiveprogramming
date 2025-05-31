for _ in range(int(input())):
	a, b = map(int,input().split())
	if a==b:
		print(-1)
	else:
		print(2**40 - max(a,b))