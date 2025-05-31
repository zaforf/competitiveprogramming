for _ in range(int(input())):
	n,s1,s2 = map(int,input().split())
	l1, l2 = [], []
	q = [(v, ind) for ind, v in enumerate(map(int,input().split()))]
	q.sort(reverse=True)
	l1t = s1
	l2t = s2
	for i in range(n):
		if l1t < l2t:
			l1.append(q[i][1]+1)
			l1t += s1
		else:
			l2.append(q[i][1]+1)
			l2t += s2
	print(len(l1)," ".join(map(str,l1)))
	print(len(l2)," ".join(map(str,l2)))