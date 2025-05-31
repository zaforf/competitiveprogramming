for _ in range(int(input())):
	n, k = map(int,input().split())
	s = input()
	if len(set([*s])) == 1:
		print("NO")
	else:
		if k == 0 and s >= s[::-1]:
			print("NO")
		else:
			print("YES")