

def lasttrue (l,h,f):
    while (l<h):
        mid = (l+h+1)//2
        if (f(mid)):
            l = mid
        else:
            h = mid-1
    return l

n,e = map(int,input().split())
inp = sorted(list(map(int,input().split())))

def check(x):
    # 1 2 3 100
    ans = 0
    for i in range(len(inp)-x,len(inp)):
        if (inp[i]+1<x):
            return False
        else:
            ans+=max(x-inp[i],0)

    return ans<=e

a = lasttrue(0,len(inp),check)
print(a)
