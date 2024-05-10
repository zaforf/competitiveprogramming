N = int(input())
r = [*map(int,input().split())]
from fractions import Fraction

ans = Fraction()
for i in range(N):
	for j in range(i+1,N):
		for k in range(1,r[j]+1):
			ans += Fraction(max(0,r[i]-k),r[j]*r[i])
print('%.6f' % (ans))