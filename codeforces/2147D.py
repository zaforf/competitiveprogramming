import random

for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	# compress to v: count(v)
	c = {}
	# get random int to xor numbers to prevent hash hacking
	xor_shuffle = random.randint(0, 1 << 30)
	for v in a:
		v ^= xor_shuffle
		if v in c:
			c[v] += 1
		else:
			c[v] = 1
	# list of counts of odd v
	l = []
	tot = 0
	for v in c:
		if (v^xor_shuffle) % 2 == 1:
			l.append(c[v])
			tot += c[v]*((v^xor_shuffle)-1)
		else:
			tot += c[v]*(v^xor_shuffle)

	l.sort(reverse=True)
	x,y = 0, 0
	for i in range(len(l)):
		if i % 2 == 0:
			x += l[i]
		else:
			y += l[i]
	print(x+tot//2, y+tot//2)
