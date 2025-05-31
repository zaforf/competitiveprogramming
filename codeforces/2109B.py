from math import log2, ceil

t = int(input())
for _ in range(t):
	n, m, a, b = map(int, input().split())

	print(min(ceil(log2(n)) + ceil(log2(b)),
			  ceil(log2(n)) + ceil(log2(m-b+1)),
			  ceil(log2(a)) + ceil(log2(m)),
			  ceil(log2(n-a+1)) + ceil(log2(m))	)+1)
