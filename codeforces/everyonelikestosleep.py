N = int(input())
def timedif(h1,m1,h2,m2):
    if h1==h2:
        return m2-m1
    return m2+60-m1+(h2-h1-1)*60

for i in range(N):
    a,H,M = map(int,input().split())
    alms = set([tuple(map(int,input().split())) for i in range(a)])
    ans = 0
    while ((H+(M)//60)%24,(M)%60) not in alms:
        ans+=1
        M+=1
        H+=M//60
        M%=60
        H%=24
    print(ans//60,ans%60)