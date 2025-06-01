for _ in range(int(input())):
	n,k = map(int, input().split())
	a = [*map(int, input().split())]
	s = sum(a)
	mx = max(a)
	ind_mx = a.index(mx)
	a[ind_mx] -= 1
	if max(a) - min(a) > k:
		print("Jerry")
		continue
	if s % 2 == 0:
		print("Jerry")
	else:
		print("Tom")