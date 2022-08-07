N = int(input())

def hanoi(n,s,e,u):
    if n==1:
        return [[s,e]]
    return hanoi(n-1,s,u,e) + [[s,e]] + hanoi(n-1,u,e,s)

ans = hanoi(N,1,3,2)
print(len(ans))
print("\n".join([str(a)+" "+str(b) for a,b in ans]))