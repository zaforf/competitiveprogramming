n = int(input())
rows = [set() for _ in range(n)]
cols = [set() for _ in range(n)]

def mex(a,b):
	x = 0
	while x in a or x in b:
		x += 1
	return x

for i in range(n):
	for j in range(n):
		x = mex(rows[i], cols[j])
		rows[i].add(x)
		cols[j].add(x)
		print(x, end=' ')
	print()