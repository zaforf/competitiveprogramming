# import sys
# sys.stdin = open("std.in", "r")
# sys.stdout = open("std.out", "w")

T = int(input())
removecost = [0,1]
for i in range(2,200001):
    removecost.append(removecost[i//2]+1)

for _ in range(T):
    s = input()
    ans = float('inf')
    for i in range(ord('a'),ord('z')+1):
        cnt,curr = 0,0
        char = chr(i)
        for j in range(len(s)):
            if s[j]!=char:
                cnt+=1
            else:
                curr = max(curr,cnt)
                cnt=0
        curr = max(curr,cnt)
        ans = min(ans,curr)
    print(removecost[ans])
