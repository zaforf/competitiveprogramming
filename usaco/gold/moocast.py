# not working

import time
read = open("moocast.in", "r").readline
write = open("moocast.out", "w").write
t0 = time.time()
N = int(read())
coords = []
for i in range(N):
    a,b = map(int,read().split())
    coords.append([a,b,i])

def check(x):
    unvis = [True for i in range(N)]
    search = [coords[0]]
    while search:
        curr = search.pop()
        unvis[curr[2]] = False
        for c in coords:
            if (c[0]-curr[0])**2 + (c[1]-curr[1])**2 <= x and unvis[c[2]]:
                search.append(c)
                unvis[c[2]] = False
    return sum(unvis)==0

l,h = 0,int(1e9)
while (l<h):
    med = (l+h)//2
    if (check(med)):
        h = med
    else:
        l = med+1
write(str(l))
print(time.time()-t0)
