n = int(input())
maxs = list(map(int,input().split()))
maxs.sort()
ans = 0
cnt = 1
money = 0
for i in range(n-1,-1,-1):
    if cnt*maxs[i]>=money:
        ans = maxs[i]
        money = cnt*maxs[i]
    cnt+=1
print(money,ans)