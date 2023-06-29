def first_true(lo, hi, f):
	hi += 1
	while lo < hi:
		mid = (lo + hi) // 2
		if f(mid):
			hi = mid
		else:
			lo = mid + 1
	return lo


def b(x):
	i=0
	for _ in range(3):
		diff = A[i]+2*x
		while i<N and A[i]<=diff:
			i+=1
		if i==N: return True
	return i==N
	

for _ in range(int(input())):
	N = int(input())
	A = [*map(int,input().split())]
	A.sort()
	if N<=3:
		print(0)
	else:
		ans = first_true(0,int(1e9),b)
		print(ans)
