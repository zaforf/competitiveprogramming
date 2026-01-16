r,c = map(int,input().split())

sr,sc = map(int,input().split())
sr -= 1
sc -= 1
er,ec = map(int,input().split())
er -= 1
ec -= 1

maze = [input() for _ in range(r)]

d = [(0,1),(-1,0),(0,-1),(1,0)]
c_dir = 0

# While Carl is not yet in the destination square.
# – If Carl can turn left by 90 degrees and face an empty square, he will turn left 90 degrees and
# then move forward by one square.
# – Otherwise, if Carl can move forward by one square, he will do so.
# – Otherwise, he will turn right 90 degrees.

inside = lambda x,y: 0 <= x < r and 0 <= y < c
vis = [[0 for _ in range(c)] for _ in range(r)]


while (sr,sc) != (er,ec):
	l_dir = (c_dir + 1) % 4
	lc,rc = sr + d[l_dir][0], sc + d[l_dir][1]
	vis[sr][sc] += 1
	if vis[sr][sc] > 8:
		break
	if inside(lc,rc) and maze[lc][rc] == '0':
		c_dir = l_dir
		sr,sc = lc,rc
	else:
		fc,fr = sr + d[c_dir][0], sc + d[c_dir][1]
		if inside(fc,fr) and maze[fc][fr] == '0':
			sr,sc = fc,fr
		else:
			c_dir = (c_dir - 1) % 4

if (sr,sc) == (er,ec):
	print(1)
else:
	print(0)
