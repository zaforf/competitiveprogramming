for _ in range(int(input())):
	N = int(input())
	A = [*map(int,input().split())]
	A.sort()
	if N<2:
		print(0)
	else:
		N//=2
		print(sum(A[-N:])-sum(A[:N]))