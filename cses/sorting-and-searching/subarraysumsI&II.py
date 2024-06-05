# import sys

# sys.stdin = open("std.in", "r")
# sys.stdout = open("std.out", "w")

n,target=map(int,input().split())
array = list(map(int,input().split()))
csum=0
ans=0
cnt={0:1}
for i in array:
    csum+=i
    if csum in cnt:
        cnt[csum]+=1
    else:
        cnt[csum]=1
    if csum-target in cnt:
        ans+=cnt[csum-target]
# print(cnt)
print(ans-(array.count(0) if target==0 else 0))