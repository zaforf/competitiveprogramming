n = int(input())

def check(k):
    res = 0
    for i in range(min(k+1,len(vals))):
        res += vals[i]*-((d-i)//-(k+1))
    return res>=c


def binsearch(): # find last true
    lo,hi = 0,int(2*10e5)
    while lo<hi:
        med = (lo+hi+1)//2
        if check(med):
            lo=med
        else:
            hi=med-1
    return lo



for i in range(n):
    q,c,d = map(int,input().split())
    vals = list(map(int,input().split()))
    vals.sort(reverse=True)
    if c//vals[0]>d:
        print("Impossible")
        continue
    if sum(vals[:d])>=c:
        print("Infinity")
        continue
    ans=binsearch()
    if ans==0:
        if check(0):
            print(0)
        else:
            print("Impossible")
    else:
        print(ans)

        
