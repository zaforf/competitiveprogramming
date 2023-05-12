# import sys
# sys.stdin = open("std.in", "r")
# sys.stdout = open("std.out", "w")

T = int(input())
for _ in range(T):
    n = int(input())
    original = list(map(int,input().split()))
    changed = list(map(int,input().split()))
    l,r=-1,-1
    for i in range(1,n):
        if original[i]^changed[i]:
            r=i
            if l==-1:
                l=i
    while l>0 and changed[l-1]<=changed[l]:
        l-=1
    while r+1<n and changed[r]<=changed[r+1]:
        r+=1
    print(l+1,r+1)