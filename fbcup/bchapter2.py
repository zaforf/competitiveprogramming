read = open("chap21.txt", "r").readline
write = open("well.txt", "w").write

T = int(read())
for t in range(T):
    ans = 0
    Q = int(read())
    xs,ys = [],[]
    for q in range(Q):
        a,b = map(int,read().split())
        xs.append(a)
        ys.append(b)
    Q = int(read())
    qxs,qys = [],[]
    for q in range(Q):
        a,b = map(int,read().split())
        qxs.append(a)
        qys.append(b)
    l,summ,cnt = 0,0,0
    for x in xs:
        summ += x
        l += x*x
        cnt += 1
    for qx in qxs:
        ans += (l-qx*(2*summ-(qx-1)*cnt) + qx*cnt)%1000000007;
        ans %= 1000000007
    l,summ,cnt = 0,0,0
    for y in ys:
        summ += y
        l += y*y
        cnt += 1
    for qy in qys:
        ans += (l-qy*(2*summ-(qy-1)*cnt) + qy*cnt)%1000000007;
        ans %= 1000000007
    write("Case #"+str(t+1)+": "+str(ans)+"\n")