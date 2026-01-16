r,c = map(int,input().split())
g = [[*map(int,input().split())] for _ in range(r)]

s,t = map(int,input().split())
z = [input() for _ in range(s)]

tot = sum(map(sum,g))
mn = tot
for d in range(4):
	for i in range(r-s+1):
		for j in range(c-t+1):
			sm = 0
			for x in range(s):
				for y in range(t):
					if z[x][y] == '#':
						sm += g[i+x][j+y]
			mn = min(mn, sm)
	# rotate z
	z = [''.join(z[s-1-x][y] for x in range(s)) for y in range(t)]
	s,t = t,s
print(tot-mn)
