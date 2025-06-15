from math import log2

def row(x,r):
	l2 = 2**int(log2(x))
	if l2 == x:
		return [r]*x
	v = row(x - l2, r)
	return v + [0]*(x-2*len(v)) + v

for _ in range(int(input())):
	n,k = map(int, input().split())
	print(*row(n,k))