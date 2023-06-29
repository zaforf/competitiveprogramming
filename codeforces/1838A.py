for _ in range(int(input())):
	N = int(input())
	A = [*map(int,input().split())]
	print(min(A) if min(A)<0 else max(A))
