n,m,x = map(int,input().split())
grids = []
for i in range(x+1):
	input()
	grid = [[int(c) for c in input()] for i in range(n)]
	grids.append(grid)

delta = [[0 for i in range(m)] for i in range(n)]
for i in range(1, x+1):
	for j in range(n):
		for k in range(m):
			if grids[i][j][k] != grids[i-1][j][k]:
				delta[j][k] = 1

for j in range(n):
		for k in range(m):
			for i in range(x+1):
				if delta[j][k] > 0 and grids[i][j][k] == grids[i][j][k-1]:
					delta[j][k] += 1

for j in range(n):
	for k in range(m):
		if delta[j][k] > 0:
			delta[j][k] -= 1

sorts = []
for i in range(x+1):
	mn = 101
	for j in range(n):
		for k in range(m):
			if delta[j][k] > 0 and grids[i][j][k] == grids[i][j][k-1]:
				mn = min(mn, delta[j][k])
	sorts.append((mn, grids[i], i))

sorts.sort(reverse=True)
print(sorts[0][2]+1)
ops = []
for i in range(1, x+1):
	for j in range(n):
		for k in range(m):
			if grids[sorts[i][2]][j][k] != grids[sorts[i-1][2]][j][k]:
				ops.append(f"1 {j+1} {k+1}")
	ops.append(f"2 {sorts[i][2]+1}")

print(len(ops))
for op in ops:
	print(op)

