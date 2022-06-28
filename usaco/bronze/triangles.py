read = open("triangles.in", "r").readline
write = open("triangles.out", "w").write

n = int(read())
pts = []
for i in range(n):
    pts.append(list(map(int,read().split())))
ans = 0
for i in range(n):
    for i2 in range(n):
        if i==i2: continue
        for i3 in range(n):
            if i3==i2 or i3==i: continue
            if pts[i][0]==pts[i2][0] and pts[i][1]==pts[i3][1]:
                ans = max(ans,abs(pts[i][1]-pts[i2][1])*abs(pts[i][0]-pts[i3][0]))
write(str(ans))