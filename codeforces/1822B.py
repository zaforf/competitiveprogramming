# import sys
# sys.stdin = open("std.in", "r")
# sys.stdout = open("std.out", "w")

T = int(input())

for _ in range(T):
    n = int(input())
    vals = list(map(int,input().split()))
    vals.sort()
    print(max(vals[0]*vals[1],vals[-1]*vals[-2]))