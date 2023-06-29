for _ in range(int(input())):
	N = int(input())
	s = input()
	l = 0
	while l<N:
		print(s[l],end="")
		r = l+1
		while r<N and s[r]!=s[l]:
			r+=1
		l=r+1
	print()