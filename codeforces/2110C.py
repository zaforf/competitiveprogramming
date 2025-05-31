for _ in range(int(input())):
	n = int(input())
	a = [*map(int,input().split())]
	loc = [0,0]
	bad = False
	ans = []
	ranges = []
	heights = []
	real_delta = []
	maxh = 0
	for i in range(n):
		if a[i] == 1:
			loc = [loc[0]+1, loc[1]+1]
		elif a[i] == -1:
			loc = [loc[0], loc[1]+1]


		l,r = map(int,input().split())
		loc = [max(loc[0],l), min(loc[1],r)]
		if loc[0] > loc[1]:
			bad = True
		heights.append(loc[1])
		maxh = max(maxh, loc[1])
		ranges.append([loc[0],loc[1]])
	if bad:
		print(-1)
		continue

	need_to_be_at = [ranges[i][0] for i in range(n)]
	for i in range(n-2,-1,-1):
		need_to_be_at[i] = max(need_to_be_at[i], need_to_be_at[i+1]-abs(a[i+1]))
	
	c = 0
	for i in range(n):
		if a[i] == -1:
			if c<need_to_be_at[i]:
				ans.append(1)
				c += 1
			else:
				ans.append(0)
		else:
			ans.append(a[i])
			c += a[i]
	print(" ".join(map(str,ans)))