for _ in range(int(input())):
	n = int(input())
	if (n%2==0):
		print(-1)
		continue

	if (n==1):
		print(1)
		continue

	a = [0 for i in range(n)]
	l = 0
	r = n-1
	b = 1
	while l<=r:
		if (b%2==1):
			a[l] = b
			l += 1
			b += 1
		else:
			a[r] = b
			r -= 1
			b += 1
	print(" ".join(map(str,a)))