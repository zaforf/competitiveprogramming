# import sys
# sys.stdin = open("std.in", "r")
# sys.stdout = open("std.out", "w")

T = int(input())

def solve():
    for i in range(len(vals)):
        if i%k!=vals[i]%k:
            if len(swap)==2:
                print(-1)
                return
            swap.append((i%k,vals[i]%k))
    if len(swap)==1:
        print(-1)
        return
    if len(swap)==2 and swap[0][::-1]==swap[1]:
        print(1)
        return
    print(0)
    return


for _ in range(T):
    n,k = map(int,input().split())
    vals = list(map(int,input().split()))
    vals = [i-1 for i in vals]
    swap = []
    solve()
            