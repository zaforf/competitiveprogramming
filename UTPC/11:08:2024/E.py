n, m = map(int,input().split())

s = [*map(int,input().split())]

for i in range(n):
	a = [*map(int,input().split())]
	if (str(a+a).find(str(s)[1:][:-1])>=0):
		print(i+1)
		break
else:
	print(-1)