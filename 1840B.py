for _ in range(int(input())):
	a,b = map(int,input().split())
	if a>b and b<=30:
		print(min(a+1,2**b))
	else:
		print(a+1)
