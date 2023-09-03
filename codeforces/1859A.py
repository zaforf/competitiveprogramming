for i in range(int(input())):
	N = int(input())
	a = [*map(int,input().split())]
	if len(a)==a.count(min(a)):
		print(-1)
	else:
		print(x:=a.count(min(a)),N-x)
		print(" ".join([str(min(a)) for i in range(x)]))
		print(" ".join([str(b) for b in a if b!=min(a)]))
