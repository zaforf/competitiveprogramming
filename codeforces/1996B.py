for _ in range(int(input())):
	n, k = map(int,input().split())
	grid = [input() for i in range(n)]
	ans = [[0 for i in range(n//k)] for i in range(n//k)]
	for i in range(n//k):
		for j in range(n//k):
			ans[i][j] = grid[i*k][j*k]
	ans = [[*map(str,row)] for row in ans]
	for row in ans: print("".join(row))