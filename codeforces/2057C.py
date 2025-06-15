for _ in range(int(input())):
	l, r = map(int, input().split())
	# find k, the highest bit where l and r differ

	k = 32
	while (l >> k) == (r >> k):
		k -= 1
	x = r - (r & ((1 << k) - 1))
	print(x,x-1,r if x-2 < l else x-2)
