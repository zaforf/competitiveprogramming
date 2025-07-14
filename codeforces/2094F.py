for _ in range(int(input())):
	n,m,k = map(int,input().split())
	e, ce = 2, 0
	o, co = 1, 0
	cnt = n*m//k
	for i in range(n):
		row = []
		for j in range(m):
			if (i+j)%2 == (k%2) and e <= k:
				row.append(e)
				ce += 1
				if ce == cnt:
					e += 2
					ce = 0
			else:
				row.append(o)
				co += 1
				if co == cnt:
					o += 2
					co = 0
		if len(row) > 2 and row[-1] == row[-2]:
			t = row[0]
			row[0] = row[-1]
			row[-1] = t
		print(*row)
