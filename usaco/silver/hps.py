read = open("hps.in", "r").readline
write = open("hps.out", "w").write

n = int(read())
p = [[0,0,0]]
s = ["H","P","S"]
x = [0,0,0]
for _ in range(n):
    x[s.index(read().strip())]+=1
    p.append(list(x))
ans = 0
for i in range(len(p)-1):
    b,a=0,0
    b=max(p[i])
    a=max((p[-1][0]-p[i][0],p[-1][1]-p[i][1],p[-1][2]-p[i][2]))
    ans = max(ans,b+a)
write(str(ans))