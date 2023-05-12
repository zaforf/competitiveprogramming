# import sys
# sys.stdin = open("std.in", "r")
# sys.stdout = open("std.out", "w")

T = int(input())

for _ in range(T):
    n,k = map(int,input().split())
    d = False
    for i in range(n+1):
        j = n-i
        if i*(i-1)+j*(j-1)==2*k:
            print("YES")
            print(" ".join(["-1"]*i)+" "+" ".join(["1"]*j))
            d = True
            break
    if not d:
        print("NO")