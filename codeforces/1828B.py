from math import gcd

for _ in range(int(input())):
	N = int(input())
	P = [*map(int,input().split())]
	ANS = P[0]-1
	for i in range(N):
		ANS = gcd(ANS,P[i]-i-1)
	print(ANS)