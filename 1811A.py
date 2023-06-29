for _ in range(int(input())):
	N,D = map(int,input().split())
	D = str(D)
	num = input()
	ans = []
	done = False
	for l in num:
		if D>l and not done:
			ans.append(D)
			done = True
		ans.append(l)
	if not done:
		ans.append(D)
	print("".join(ans))