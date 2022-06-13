j = int(input())
cows = list(map(int,input().split()))
heights = list(map(int,input().split()))

def check(a,b):
    if len(b)==0:
        return 1
    else:
        ret = 0
        for i,cow in enumerate(a):
            if cow != 0 and cow<=b[-1]:
                a[i]=0
                temp = b.pop()
                ret += check(a,b)
                b.append(temp)
                a[i]=cow
        return ret
print(check(cows,heights))
 