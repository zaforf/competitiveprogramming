T = int(input())

for _ in range(T):
	N = int(input())
	grid = [[*map(int,input().split())] for i in range(N)]
	relevant = [None for i in range(N)]
	columns = [[] for i in range(N)]
	for i in range(N):
		for j in range(N):
			if (grid[j][i]>0):
				columns[i].append((j,grid[j][i],len(columns[i])))

	for i in range(N):
		for j in range(N):
			if len(columns[j])>0 and (relevant[j] is None or (relevant[j][2]+1<len(columns[j]) and abs(columns[j][relevant[j][2]+1][1]-i)<abs(relevant[j][0]-i))):
				relevant[j] = (columns[j][0] if relevant[j] is None else columns[j][relevant[j][2]+1])
		for j in range(N):
			mint,mant = -float('inf'),float('inf')
			for k in range(N):
				if relevant[k] is None: continue
				mint = max(mint,relevant[k][1]-abs(i-relevant[k][0])-abs(k-j))
				mant = min(mant,relevant[k][1]+abs(i-relevant[k][0])+abs(k-j))
			if (mint==mant):
				grid[i][j] = mint
	for i in range(N):
		print(*grid[i],"")

