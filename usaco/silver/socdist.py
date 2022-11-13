read = open("socdist.in", "r").readline
write = open("socdist.out", "w").write

n, r = map(int,read().split())
rngs = []

for i in range(r):
    rngs.append(list(map(int,read().split())))
rngs.sort()

def lasttrue(l,r,c):
    while (l<r):
        med = (l+r+1)//2
        print(l,r,0)
        if c(med):
            l = med
        else:
            r = med-1
    return l

def ceildiv(a,b):
    return -(a//-b)

def check(x):
    cnt = 0
    last = 0
    for rng in rngs:
        b = max(rng[0],last)
        if rng[1]<b: continue
        cnt += ceildiv(rng[1]-b+1,x)
        last = ceildiv(rng[1]-b+1,x)*x+b
        if cnt>=n: 
            return True
    return cnt>=n


write(str(lasttrue(0,int(10e18),check)))