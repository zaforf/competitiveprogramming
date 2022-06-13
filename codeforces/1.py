n = int(input())

for _ in range(n):
    a,b,c = map(int,input().split())
    stra, strb = input(),input()
    stra = list(reversed(sorted(list(stra))))
    strb = list(reversed(sorted(list(strb))))
    used = 0
    ans = []
    while len(stra)>0 and len(strb)>0:
        if used==c:
            ans.append(strb.pop())
            used=-1
        elif used==-c:
            ans.append(stra.pop())
            used=1
        elif stra[-1]<strb[-1]:
            ans.append(stra.pop())
            if used>0:
                used+=1
            else:
                used=1
        else:
            ans.append(strb.pop())
            if used<0:
                used-=1
            else:
                used=-1
    print("".join(ans))
