T = int(input())
for t in range(T):
    n,k = map(int,input().split())
    str = input()
    ans = ["." for i in range(n)]
    lastg,lasth = -1,-1
    cnt = 0
    for i in range(n):
        if str[i]=="G":
            if lastg==-1 or i>lastg+k:
                #unchecked
                if i+k>=n:
                    x = n-1
                    while ans[x]!=".":
                        x-=1
                    lastg=x
                    ans[x]="G"
                else:
                    ans[i+k]="G"
                    lastg=i+k
        if str[i]=="H":
            if lasth==-1 or i>lasth+k:
                #unchecked
                if i+k>=n:
                    x = n-1
                    while ans[x]!=".":
                        x-=1
                    lasth=x
                    ans[x]="H"
                else:
                    ans[i+k]="H"
                    lasth=i+k
    print(len(ans)-ans.count("."))
    print("".join(ans))