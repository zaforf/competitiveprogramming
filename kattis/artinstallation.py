r, g, b = map(int, input().split())
has_a, has_g, has_b = map(int, input().split())
buy_rg, buy_gb = map(int, input().split())

need_a = max(r - has_a, 0)
need_b = max(b - has_b, 0)
tot = 0

if need_a > buy_rg:
    print(-1)
    exit()
buy_rg -= need_a
tot += need_a

if need_b > buy_gb:
    print(-1)
    exit()
buy_gb -= need_b
tot += need_b

need_g = max(g - has_g, 0)
if need_g > buy_rg + buy_gb:
    print(-1)
else:
    tot += need_g
    print(tot)
