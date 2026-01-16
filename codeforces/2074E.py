from random import randint

def solve():
	n = int(input())

	a, b, c = 1, 2, 3

	for _ in range(75):
		print("?", a, b, c)
		d = int(input())
		if d == 0:
			print("!", a, b, c)
			return
		r = randint(1, 3)
		if r == 1:
			a = d
		elif r == 2:
			b = d
		else:
			c = d

for t in range(int(input())):
	solve()