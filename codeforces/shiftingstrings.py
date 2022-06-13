n = int(input())
import math

for _ in range(n):
    sz = int(input())
    string = input()
    unv = set(range(1,sz+1))
    adj = list(map(int,input().split()))
    ans = 1
    while unv:
        x = 0
        next = [unv.pop()]
        while next:
            x+=1
            curr = next.pop()
            if adj[curr-1] in unv:
                next.append(adj[curr-1])
                unv.remove(adj[curr-1])
        ans = math.lcm(ans,x)
    print(ans)




