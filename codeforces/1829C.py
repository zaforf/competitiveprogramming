for _ in range(int(input())):
	N = int(input())
	s1,s2,sb = float('inf'),float('inf'),float('inf')
	for _ in range(N):
		a,b = map(int,input().split())
		if b>=10:
			s1=min(s1,a)
		if b%2==1:
			s2=min(s2,a)
		if b==11:
			sb=min(sb,a)
	x = min(s1+s2,sb)
	print(x if x!=float('inf') else -1)