N = int(input())

grid = [[*map(int,input().split())]for i in range(N)]
ans1 = 0
for i in range(N):
	a = sum([grid[i][b] for b in range(len(grid[i])) if b%2==1])
	ans1 += max(sum(grid[i])-a,a)

grid = [*zip(*grid)]

ans2 = 0
for i in range(N):
	a = sum([grid[i][b] for b in range(len(grid[i])) if b%2==1])
	ans2 += max(sum(grid[i])-a,a)

print(max(ans1,ans2))