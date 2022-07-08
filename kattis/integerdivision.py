n,k = map(int,input().split())
inp = list(map(int,input().split()))
cnt = {}
for i in inp:
    if i//k not in cnt:
        cnt[i//k]=0
    cnt[i//k]+=1
ans = 0
for key in cnt:
    ans += (cnt[key]*(cnt[key]-1))//2
print(ans)