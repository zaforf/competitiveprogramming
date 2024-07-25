T = int(input())

for _ in range(T):
	a,b,c = map(int,input().split())
	x = sorted([a,b,c])
	x[0] += 1
	x = sorted(x)
	x[0] += 1
	x = sorted(x)
	x[0] += 1
	x = sorted(x)
	x[0] += 1
	x = sorted(x)
	x[0] += 1
	print(x[0]*x[1]*x[2])