for _ in range(int(input())):
	N = int(input())
	A = [*range(1,N+1)]
	print(*[[2,1][N%2]*i for i in A])