p = int(input())
ev=0
od=0
for i in map(int,input().split()):
    if i%2!=0:
        od+=1
    else:
        ev+=1
ans = 0
while (True):
    if ev>0:
        ev-=1
        ans+=1
    elif od>1:
        od-=2
        ans+=1
    else:
        break
    if od==3:
        od-=3
        ans+=1
    elif od>0:
        od-=1
        ans+=1
    else:
        break
print(ans)