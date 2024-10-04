from math import isqrt

def cnt(m):
	return m-isqrt(m)

for _ in range(int(input())):
	n = int(input())
	l = 1
	r = 2000000000000000000
	while (l<r):
		mid = (l+r)//2
		if (mid-isqrt(mid)<n): l = mid+1
		else: r = mid
	print(l)