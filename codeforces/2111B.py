def fib(n):
	if n == 0:
		return 0
	elif n == 1:
		return 1
	else:
		a, b = 1, 1
		for _ in range(2, n + 1):
			a, b = b, a + b
		return b

for _ in range(int(input())):
	n, m = map(int, input().split())
	boxes = [map(int, input().split()) for _ in range(m)]
	big, med = fib(n), fib(n-1)
	for w,l,h in boxes:
		# can two boxes fit in the big box?
		if big <= w and big <= l and big+med <=h:
			print("1", end="")
			continue
		if big+med <= w and big <= l and big <= h:
			print("1", end="")
			continue
		if big <= w and big+med <= l and big <= h:
			print("1", end="")
			continue
		print("0", end="")
	print()