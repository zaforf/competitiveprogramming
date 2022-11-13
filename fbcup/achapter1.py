read = open("consecutive_cuts_chapter_1_input.txt", "r").readline
write = open("cuts.txt", "w").write
T = int(read())
for t in range(T):
    n,k = map(int,read().split())
    if n==2:
        s = list(map(int,read().split()))
        e = list(map(int,read().split()))
        if s==e and k%2==0:
            write("Case #"+str(t+1)+": YES\n")
        elif s!=e and k%2==1:
            write("Case #"+str(t+1)+": YES\n")
        else:
            write("Case #"+str(t+1)+": NO\n")
        continue
    inp = list(map(int,read().split()))
    s,e = [],[]
    i = 0
    ls,le = 0,0
    while len(s)<n:
        if i==n: i=0
        if s and inp[i]<s[0]:
            s.clear()
            ls=i
        s.append(inp[i])
        i+=1
    inp = list(map(int,read().split()))
    i = 0
    while len(e)<n:
        if i==n: i=0
        if e and inp[i]<e[0]:
            e.clear()
            le=i
        e.append(inp[i])
        i+=1
    if s==e and k>0 and ls!=le:
        write("Case #"+str(t+1)+": YES\n")
    elif k!=1 and ls==le and s==e:
        write("Case #"+str(t+1)+": YES\n")
    else:        
        write("Case #"+str(t+1)+": NO\n")