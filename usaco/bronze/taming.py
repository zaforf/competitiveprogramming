# 4
# -1 -1 -1 1
read = open("taming.in", "r").readline
write = open("taming.out", "w").write
N = int(read())
inp = list(map(int,read().split()))
iq = {0:0}
cnt = 0
for i in range(N):
    if inp[i]!=-1:
        if inp[i] > cnt:
            write(str(-1))
            quit()
        cnt = inp[i]
        iq[i-inp[i]] = inp[i]
    cnt+=1
minans,maxans = 0,0
lastkey=0
for i in range(N):
    if i in iq:
        lastkey=i
        minans+=1
        maxans+=1
    else:
        if i>lastkey+iq[lastkey]:
            maxans+=1
write(str(minans)+" "+str(maxans))