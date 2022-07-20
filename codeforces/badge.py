N = int(input())
succ = [0] + list(map(int,input().split()))
ans = [-1 for i in range(N+1)]
inloop = False
reached = [0 for i in range(N+1)]

def dfs(i):
    global inloop
    reached[i]+=1
    if ans[i] != -1:
        return
    if reached[i]==2:
        inloop = True
    if inloop:
        ans[i] = i
        return
    else:
        dfs(succ[i])
        if inloop and reached[i]==2:
            inloop = False
        elif inloop:
            ans[i] = i
        else:
            ans[i] = ans[succ[i]]
        return
    

for i in range(1,N+1):
    if ans[i]==-1:
        dfs(i)
print(*ans[1:])

