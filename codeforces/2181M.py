for _ in range(int(input())):
	x, y = input(), input()
	y = "0" + y
	x, y = [int(v) for v in x], [int(v) for v in y]

	n = len(x)
	ans = 0
	curr = 0
	for i in range(n):
		exp = y[i]^x[i]

		if exp == y[i+1]:
			ans += (curr+1)//2
			curr = 0
		else:
			curr += 1

	ans += (curr+1)//2
	print(ans)