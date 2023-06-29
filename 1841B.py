for _ in range(int(input())):
	N = int(input())
	X = [*map(int,input().split())]
	l = X[0]
	cut = False
	ans=["1"]
	for i in range(1,N):
		if X[i]>=l and (not cut or X[i]<=X[0]):
			ans.append("1")
			l=X[i]
		elif not cut and X[i]<=X[0]:
			cut = True
			ans.append("1")
			l=X[i]
		else:
			ans.append("0")
	print("".join(ans))