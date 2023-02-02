def solve():
    N=int(input())
    csl = list(map(int,input().split()))
    if max(csl)==min(csl):
        print(1)
        print(" ".join("1"*N))
        return
    hasdup = sum([csl[i]==csl[i-1] for i in range(len(csl))])
    if len(csl)%2==0:
        print(2)
        print(*[[1,2][i%2] for i in range(N)])
        return
    if hasdup:
        ans=[1]
        dupdone=False
        for i in range(1,len(csl)):
            if csl[i]==csl[i-1] and not dupdone:
                ans.append(ans[-1])
                dupdone=True
            else:
                ans.append((1 if ans[-1]==2 else 2))
        if not dupdone and csl[-1]==csl[0]:
            ans[-1]=ans[0]
        print(2)
        print(*ans)
        return
    ans=[[1,2][i%2] for i in range(N)]
    ans[-1]=3
    print(3)
    print(*ans)
                
t = int(input())
for _ in range(t):
    solve()