n = int(input())

for i in range(n):
    g = int(input())
    ans = g//3
    if g%3==1:
        ans+=1
    elif g%3==2:
        ans+=1
    print((ans if g!=1 else 2) if g!=4 else 2)