def solve():
    n = int(input())
    a = [*map(int, input().split())]
    cnt = {}
    for i in a: cnt[i] = cnt.get(i, 0) + 1
    accounted = 0
    l, r = 0, n
    mp = {}
    abso = n
    while accounted < n:
        found = cnt.get(l,0)
        if found == 0 and l > 0:
            print("NO")
            return
        r -= found
        accounted += found
        mp[l] = -abso
        if found > 0:
            abso -= 1
        if accounted == n:
            break

        found = cnt.get(r, 0)
        if found == 0:
            print("NO")
            return
        l += found
        accounted += found
        mp[r] = abso
        abso -= 1
    print("YES")
    for i in a:
        print(mp[i], end=' ')
    print()


for _ in range(int(input())):
    solve()