for _ in range(int(input())):
	N = int(input())
	A = [*map(int,input().split())]
	b = [False for i in range(257)]
	b[0] = True
	k = 0
	ans = []
	for i in range(N):
		k=k^A[i]
		b[k]=True
		m = 0
		for i in range(257):
			if b[i]:
				m = max(m,i^k)
		ans.append(m)
	print(max(ans))