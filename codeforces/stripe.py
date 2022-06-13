from cmath import inf

n = int(input())

for i in range(n):
    a,b = map(int,input().split())
    string = input()
    num = [0]
    ans = inf
    for i in range(a):
        num.append(num[-1]+(string[i]=="W"))
    x = 0
    while x+b<a+1:
        ans = min(ans,num[x+b]-num[x])
        x+=1
    print(ans)