from math import gcd

def getFraction(a, b):
    g = gcd(a, b)
    a //= g
    b //= g
    if a < 0 or (a == 0 and b < 0):
        a = -a
        b = -b
    return (a, b)

n = int(input())
cnt = {}
for _ in range(n):
    x, y = map(int, input().split())
    slope = getFraction(x, y)
    cnt[slope] = cnt.get(slope, 0) + 1

ans = max(cnt.values())
print(ans)
