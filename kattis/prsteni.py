from math import gcd

n = int(input())
inp = list(map(int,input().split()))
last = (inp[0],1)
for i in range(1,n):
    t, b = last[0], inp[i]*last[1]
    while gcd(t,b)>1:
        x = gcd(t,b)
        t//=x
        b//=x
    print(str(t)+"/"+str(b))
