# import sys

# sys.stdin = open("std.in", "r")
# sys.stdout = open("std.out", "w")

def solve():
    n = int(input())
    curr = list(map(int,input().split()))
    desire = list(map(int,input().split()))
    nr = int(input())
    rsz = list(map(int,input().split()))
    stack = []
    need = {}
    for i in range(len(desire)):
        if curr[i]<desire[i]:
            print("NO")
            return
        while stack and stack[-1]<desire[i]:
            stack.pop()
        if (curr[i]!=desire[i] and (not stack or stack[-1]!=desire[i])):
            need[desire[i]]=need.get(desire[i],0)+1
            stack.append(desire[i])
    cnt = {}
    # print(need)
    for i in rsz:
        cnt[i]=cnt.get(i,0)+1
    # print(cnt)
    for k in need:
        if need[k]>cnt.get(k,0):
            print("NO")
            return
    print("YES")

T = int(input())
for _ in range(T):
    solve()


