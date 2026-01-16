def mexify(a):
	n = len(a)
	mex = 0
	count = [0] * (n + 1)
	for x in a:
		if x <= n:
			count[x] += 1
	for i in range(n + 1):
		if count[i] == 0:
			mex = i
			break

	b = a.copy()
	for i in range(n):
		if a[i] > mex or count[a[i]] > 1:
			b[i] = mex

	return b

for _ in range(int(input())):
	n, k = map(int, input().split())
	a = list(map(int, input().split()))

	if k == 1:
		print(sum(mexify(a)))
	elif k == 2:
		print(sum(mexify(mexify(a))))
	else:
		second = mexify(mexify(a))
		third = mexify(second)

		if (k - 2) % 2 == 0:
			print(sum(second))
		else:
			print(sum(third))
