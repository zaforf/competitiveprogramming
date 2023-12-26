N = int(input())

cows = set()
transformations = [(1,0),(-1,0),(0,1),(0,-1)]
needed = set()

def neighbors(i):
	a,b = i
	return sum(((a+j,b+k) in needed or (a+j,b+k) in cows) for j,k in transformations)

def doitandneighbors(i):
	for j,k in transformations:
		if (i[0]+j,i[1]+k) in cows or (i[0]+j,i[1]+k) in needed:
			fill((i[0]+j,i[1]+k))
	fill(i)

def fill(i):
	if neighbors(i)!=3: return
	a,b = i
	for j,k in transformations:
		if (a+j,b+k) not in cows and (a+j,b+k) not in needed:
			needed.add((a+j,b+k))
			doitandneighbors((a+j,b+k))
			break


for i in range(N):
	x = tuple([*map(int,input().split())])
	if x in needed:
		needed.remove(x)
	cows.add(x)
	doitandneighbors(x)
	print(len(needed))



