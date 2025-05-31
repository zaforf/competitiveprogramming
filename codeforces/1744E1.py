from math import gcd

for _ in range(int(input())):
	a,b,c,d = map(int,input().split())

	for x in range(a+1,c+1):
		s = a*b//gcd(x,a*b)
		y = d//s*s
		if y > b:
			print(x,y)
			break
	else:
		print(-1,-1)