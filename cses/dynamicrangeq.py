n,q = map(int,input().split())
inp = list(map(int,input().split()))
pfix = [0]
for i in inp:
    if pfix:
        pfix.append(pfix[-1]+i)
    else:
        pfix.append(i)
rng = [0 for i in range(len(inp)+1)]
for i in range(1,len(inp)+1):
    rng[i] = pfix[i]-pfix[i-(i&-i)]
def sumr(x):
    s = 0
    while x>0:
        s += rng[x]
        x -= (x&-x)
    return s

def upd(k,x):
    t = x
    x = x-inp[k-1]
    inp[k-1] = t
    while k<(len(inp)+1):
        rng[k] += x
        k += (k&-k)
    
for i in range(q):
    a,b,c = map(int,input().split())
    if a==1:
        upd(b,c)
    else:
        print(sumr(c)-sumr(b-1))
