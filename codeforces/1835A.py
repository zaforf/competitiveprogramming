for _ in range(int(input())):
	a,b,c,k = map(int,input().split())
	seen, val = 0, 0
	for i in range(10**(a-1), 10**a):
		mn = max(10**(b-1), 10**(c-1)-i)
		mx = min(10**b, 10**c-i)-1
		if seen + max(0, mx-mn+1) >= k:
			val = i
			break
		seen += max(0, mx-mn+1)
	else:
		print(-1)
		continue


	mn = max(10**(b-1), 10**(c-1)-val)
	mn += k - seen - 1
	print(val,"+",mn,"=",val+mn)