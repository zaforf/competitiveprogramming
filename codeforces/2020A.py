from math import log

for _ in range(int(input())):
	a,b = map(int,input().split())
	if (b==1):
		print(a)
		continue
	h = int(log(a,b))
	c = 0
	while (a > 0):
		if (a - b**h >= 0):
			m = a//(b**h)
			a -= m*b**h
			c+=m
		else:
			h-=1
	print(c)