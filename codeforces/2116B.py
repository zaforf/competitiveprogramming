MOD = 998244353

def pow(n):
    result = 1
    b = 2
    while n > 0:
        if n & 1:
            result = result * b % MOD
        b = b*b % MOD
        n >>= 1
    return result


for _ in range(int(input())):
	n = int(input())
	a = [*map(int, input().split())]
	b = [*map(int, input().split())]
	pmax, pmax_ind = -1, 0
	qmax, qmax_ind = -1, 0
	for i in range(n):
		if a[i] > pmax:
			pmax = a[i]
			pmax_ind = i
		if b[i] > qmax:
			qmax = b[i]
			qmax_ind = i

		bestbig, bestsmall = 0, 0
		if pmax > qmax:
			bestbig = pmax
			bestsmall = b[i-pmax_ind]
		elif qmax > pmax:
			bestbig = qmax
			bestsmall = a[i-qmax_ind]
		else:
			bestbig = pmax
			bestsmall = max(b[i-pmax_ind],a[i-qmax_ind])

		print((pow(bestbig) + pow(bestsmall)) % MOD, end=' ')
	print()
