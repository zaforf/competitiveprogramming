import sys
sys.setrecursionlimit(200000)

N = int(input())
succ = [0] + list(map(int,input().split()))
laststep = [-1 for i in range(N+1)]
ans = [0 for i in range(N+1)]
step, loop = 0,False

def dfs(i):
    global step,loop
    if ans[i] != 0:
        loop = False
        return
    if loop:
        ans[i] = ans[succ[i]]
        return
    if laststep[i] != -1:
        loop = True
        ans[i] = step-laststep[i]
        return
    laststep[i] = step
    step += 1
    dfs(succ[i])
    if loop:
        if ans[i] != 0:
            loop = False
        else:
            ans[i] = ans[succ[i]]
        return
    ans[i] = ans[succ[i]] + 1
    return

for i in range(1,N+1):
    if ans[i] == 0:
        dfs(i)
print(*ans[1:])