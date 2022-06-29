read = open("sleepy.in", "r").readline
write = open("sleepy.out", "w").write
from collections import deque

n = int(read())
q = deque(list(map(int,read().split())))
seen = set()
done = False
while True:
    ok = True
    x,i = 1,0
    while ok:
        if x>n:
            done = True
            break
        if i<len(q) and q[i]==x:
            x+=1
            i+=1
        elif x in seen:
            x+=1
        else:
            ok = False
    if done:
        break
    for _ in range(i+1):
        seen.add(q.popleft())
write(str(len(seen)))