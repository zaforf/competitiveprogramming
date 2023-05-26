# import sys
# sys.stdin = open("std.in", "r")
# sys.stdout = open("std.out", "w")

T = int(input())

for _ in range(T):
    n,t = map(int,input().split())
    vids = list(map(int,input().split()))
    ent = list(map(int,input().split()))
    ret = -1
    reti = -2
    timepassed=0
    for i in range(n):
        if vids[i]+timepassed<=t and ent[i]>ret:
            reti = i
            ret = ent[i]
        timepassed+=1
    print(reti+1)
