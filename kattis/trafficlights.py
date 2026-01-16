n = int(input())
ps = []
for _ in range(n):
	r, g = map(int, input().split())
	ps.append((r,r+g))


i = 1
while True:
	ok = True
	for r, p in ps:
		if i % p < r:
			ok = False
	if ok:
		print(i)
		break
	i += 1