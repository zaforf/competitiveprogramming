N = int(input())
r = [*map(int,input().split())]
from fractions import Fraction
from decimal import Decimal

ans = Fraction()
for i in range(N):
	for j in range(i+1,N):
		for k in range(1,r[j]+1):
			ans = ans + Fraction(max(0,r[i]-k),r[j]*r[i])

print((ans.numerator / Decimal(ans.denominator)).quantize(Decimal("0.000001")))