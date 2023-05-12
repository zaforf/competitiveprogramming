import sys
sys.stdin = open("std.in", "r")
sys.stdout = open("std.out", "w")

T = int(input())

def solve():
    if len(s)%2==1:
        print(-1)
        return
    for i in range(len(s)//2):
        if s[i]==s[n-i-1]:
            conflicts[ord(s[i])-ord('a')]+=1
    print(sum(conflicts),conflicts)
    if sum(conflicts)%2==1:
        print(-1)
        return
    half = sum(conflicts)//2
    for i in conflicts:
        if i>half:
            print(-1)
            return
    print(half)

for _ in range(T):
    n = int(input())
    conflicts = [0 for i in range(26)]
    s = input()
    solve()