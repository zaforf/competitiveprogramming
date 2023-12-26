N = int(input())

grid = [[*map(int,[i for i in input()])] for i in range(N)]

print(grid)
ones = sum(map(sum,grid))
print(-(N**2//-2))
if ones >= -(N**2//-2):
	print(1)
	print(N**2)
	for i in range(1,N+1):
		for j in range(1,N+1):
			print(i,j)