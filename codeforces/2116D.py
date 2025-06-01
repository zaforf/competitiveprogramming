for _ in range(int(input())):
    n, q = map(int, input().split())
    b = list(map(int, input().split()))
    
    real_ops, ops = [], []
    mp = {i: i for i in range(n)}
    p = n
    for _ in range(q):
        x, y, z = map(int, input().split())
        x,y,z = x - 1, y - 1, z - 1
        ops.append((mp[x], mp[y], p))
        mp[z] = p
        real_ops.append((x, y, z))
        p += 1

    a = [0 for _ in range(p)]
    for i in range(n):
        a[mp[i]] = b[i]

    # print(*[mp[i] for i in range(p)])
    for x, y, z in ops[::-1]:
        a[x] = max(a[x], a[z])
        a[y] = max(a[y], a[z])
        # print(a[:])

    c = a[:n]
    for x, y, z in real_ops:
        c[z] = min(c[x], c[y])

    if c==b:
        print(*a[:n])
    else:
        print(-1)
