read = open("mooyomooyo.in", "r").readline
write = open("mooyomooyo.out", "w").write

N,K = map(int,read().strip().split())
g = [read().strip() for i in range(N)]
game = [list(map(int,i)) for i in zip(*g)]
def floodfill(x,y,t):
	if x<0 or x>=10 or y<0 or y>=N: return 0
	if vis[x][y] or game[x][y]==0: return 0
	if t==-1 or t==game[x][y]:
		vis[x][y] = True
	else: return 0
	connected = 1
	connected += floodfill(x+1,y,game[x][y])
	connected += floodfill(x-1,y,game[x][y])
	connected += floodfill(x,y+1,game[x][y])
	connected += floodfill(x,y-1,game[x][y])
	return connected

def removethyself(x,y,t):
	if x<0 or x>=10 or y<0 or y>=N: return
	if game[x][y]==t:
		game[x][y]=0
		removethyself(x+1,y,t)
		removethyself(x-1,y,t)
		removethyself(x,y+1,t)
		removethyself(x,y-1,t)

def updrow(i):
	game[i] = [i for i in game[i] if i!=0]
	game[i] = [*map(int,"".join(map(str,game[i])).zfill(N))]


for i in range(10*N+1):
	cnt = 0
	vis = [[False for i in range(N)] for i in range(10)]
	for x in range(10):
		for y in range(N):
			if floodfill(x,y,-1)>=K:
				cnt += 1
				removethyself(x,y,game[x][y])
	if cnt==0: break
	for i in range(10):
		updrow(i)
write("\n".join(["".join(i) for i in [list(map(str,i)) for i in zip(*game)]]))