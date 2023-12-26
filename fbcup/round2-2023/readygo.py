import sys
sys.stdin = open("ready.in", "r")
sys.stdout = open("ready.out", "w")

T = int(input())

def floodfill(x,y):
	if x<0 or y<0 or x>=a or y>=b or grid[x][y]!="W" or vis[x][y]:
		return 0
	vis[x][y] = True
	t = cnt[x][y]
	t += floodfill(x-1,y)
	t += floodfill(x+1,y)
	t += floodfill(x,y-1)
	t += floodfill(x,y+1)
	return t

for _ in range(T):
	found = False
	a,b = map(int,input().split())
	grid = [input() for i in range(a)]
	for q in range(a):
		for t in range(b):
			if grid[q][t]!=".": continue
			grid[q] = grid[q][:t]+"B"+grid[q][t+1:]
			vis = [[False for i in range(b)] for i in range(a)]
			cnt = [[0 for i in range(b)] for i in range(a)]
			for i in range(a):
				for j in range(b):
					if grid[i][j]=="W":
						temp = 0
						if i>0 and grid[i-1][j]==".": temp +=1
						if j>0 and grid[i][j-1]==".": temp+=1
						if i<a-1 and grid[i+1][j]==".": temp+=1
						if j<b-1 and grid[i][j+1]== ".": temp +=1
						cnt[i][j] = temp

			for i in range(a):
				for j in range(b):
					if grid[i][j]=="W" and not vis[i][j]:
						if floodfill(i,j)==0:
							found = True
			grid[q] = grid[q][:t]+"."+grid[q][t+1:]
	print(f"Case #{_+1}:","YES" if found else "NO")
