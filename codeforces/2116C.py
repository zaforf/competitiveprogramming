from math import gcd
MX = 5001

for _ in range(int(input())):
    n = int(input())
    a = [*map(int,input().split())]

    g = a[0]
    for num in a:
        g = gcd(g, num)

    cnt_g = sum(1 for x in a if x == g)
    if cnt_g > 0:
        print(n - cnt_g)
        continue

    dp = {}
    for x in a:
        newdp = dp.copy()
        newdp[x] = min(newdp.get(x, MX), 1)
        for d in dp:
            sz = dp[d]
            d2 = gcd(d, x)
            newdp[d2] = min(newdp.get(d2, MX), sz + 1)
        dp = newdp

    k = dp[g]
    print((k - 1) + (n - 1))
