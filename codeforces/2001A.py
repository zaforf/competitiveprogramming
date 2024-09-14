for _ in range(int(input())):
	n = int(input())
	a = [*map(int,input().split())]
	f = [a.count(i) for i in a]
	print(n-max(f))