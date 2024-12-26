n = int(input())
c = 1

for i in range(1,n):
    print(i)
    mark = [0 for i in range(n)]
    m = {i:0 for i in range(1, n+1)}
    ans = [[] for i in range(n)]
    for j in range(n):
        if mark[j] != 0:
            m[c] = 0
            continue
        for possible_c in range(1, n+1):
            if m[possible_c] == 0:
                c = possible_c
                break
        mark[j], mark[(j+i)%n] = c, c
        ans[c-1].append((j+1, (j+i)%n+1))
        m[c] = 1
    print(ans)

