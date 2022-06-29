read = open("shell.in", "r").readline
write = open("shell.out", "w").write

n = int(read())
n1,n2,n3 = 0,0,0
curr = [1,2,3]
for _ in range(n):
    a,b,g = map(int,read().split())
    t = curr[a-1]
    curr[a-1]=curr[b-1]
    curr[b-1]=t
    if curr[g-1]==1:
        n1+=1
    elif curr[g-1]==2:
        n2+=1
    else:
        n3+=1
write(str(max((n1,n2,n3))))