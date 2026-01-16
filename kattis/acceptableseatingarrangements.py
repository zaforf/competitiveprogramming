r,c = map(int,input().split())
og = [set() for _ in range(r*c+1)]
og_grid = []
for i in range(r):
	row = list(map(int,input().split()))
	og_grid.append(row)
	for j in range(c):
		og[row[j]].add((i,j))

gol = [set() for _ in range(r*c+1)]
for i in range(r):
	row = list(map(int,input().split()))
	for j in range(c):
		gol[row[j]].add((i,j))


def swap(i,j,p,q):
	og_grid[i][j],og_grid[p][q] = og_grid[p][q],og_grid[i][j]
	og[og_grid[i][j]].discard((p,q))
	og[og_grid[i][j]].add((i,j))
	og[og_grid[p][q]].discard((i,j))
	og[og_grid[p][q]].add((p,q))

def print_grid(g):
	for row in g:
		print(*row)
	print()

# print(og_grid)
ans = []
for i in range(1,r*c+1):
	while len(gol[i]) > 0:
		bef_r,bef_c = og[i].pop()
		aft_r,aft_c = gol[i].pop()
		# print(f"Placing {i} from {(bef_r,bef_c)} to {(aft_r,aft_c)}")
		if (bef_r,bef_c) == (aft_r,aft_c):
			continue
		while og_grid[aft_r][aft_c] != i:
			v = og_grid[aft_r][aft_c]
			# find last position in row aft_r less than v
			nc = -1
			for j in range(c):
				if og_grid[bef_r][j] < v:
					nc = j
			# print(f"Swapping {v} at {(aft_r,aft_c)} with {og_grid[bef_r][nc]} at {(bef_r,nc)}")
			swap(aft_r,aft_c,bef_r,nc)
			ans.append((aft_r+1,aft_c+1,bef_r+1,nc+1))
			# print_grid(og_grid)

print(len(ans))
for a in ans:
	print(*a)