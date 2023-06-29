for _ in range(int(input())):
	X,K = map(int,input().split())
	if X%K!=0:
		print(1)
		print(X)
	else:
		print(2)
		print(X-1,1)