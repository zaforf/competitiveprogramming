from math import inf

n = int(input())
for i in range(n):
    x = int(input())
    inp = list(map(int,input().split()))
    check = list(map(int,input().split()))
    e = -1
    maxx = inf
    ok = True
    for i in range(x):
        e = max(e,inp[i]-check[i])
        if check[i]!=0:
            maxx = min(maxx,inp[i]-check[i])
    if (e==maxx or maxx is inf) and (maxx>=0 and e>=0):
         print("YES")
    else:
        print("NO")