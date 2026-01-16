from random import randint

for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	cnt = {}
	# random xor to avoid hack
	xor = randint(0, 10**9)
	for x in a:
		v = x ^ xor
		if v not in cnt:
			cnt[v] = 0
		cnt[v] += 1

	symm = 0
	c = 0
	leftover = []
	for k, v in cnt.items():
		k = k ^ xor
		symm += (v - v % 2) * k
		c += (v - v % 2) // 2
		if v % 2 == 1:
			leftover.append(k)
	if symm == 0:
		print(0)
		continue
	ans = symm if c > 1 else 0

	leftover.sort(reverse=True)
	for v in leftover:
		if v < symm:
			ans = max(ans, symm + v)
	for i in range(len(leftover)-1):
		a,b = leftover[i], leftover[i+1]
		if b <= a - symm:
			continue
		ans = max(ans, symm + a + b)

	print(ans)