import math

T = int(input())
for _ in range(T):
    n = int(input())
    vals = input()
    cnt=0
    ans=[]
    for i in range(len(vals)):
        if vals[i]=="1":
            cnt+=1
        ans.append(math.comb(i+1,cnt))
    print(*ans)