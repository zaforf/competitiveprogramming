from fractions import Fraction
from decimal import Decimal, ROUND_HALF_EVEN, getcontext

N = int(input())
r = list(map(int, input().split()))

ans = Fraction()

for i in range(N):
    for j in range(i+1, N):
        m = min(r[j], r[i] - 1)
        if m > 0:
            ans += Fraction(m * (2*r[i] - m - 1), 2 * r[i] * r[j])

getcontext().prec = 100
result = (Decimal(ans.numerator) / Decimal(ans.denominator)) \
		.quantize(Decimal("0.000001"), rounding=ROUND_HALF_EVEN)

print(result)
