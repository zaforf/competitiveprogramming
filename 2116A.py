for _ in range(int(input())):
	a,b,c,d = map(int, input().split())
	x = min(a, c)
	y = min(b, d)
	if x >= y:
		print("Gellyfish")
	else:
		print("Flower")