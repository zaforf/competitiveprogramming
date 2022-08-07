from math import inf
N = int(input())

for i in range(N):
    n = int(input())
    arr = list(map(int,input().split()))
    ans = inf
    inn = set()
    for j in reversed(range(n)):
        inn.add(arr[j])
        if len(inn) == n-j:
            ans = min(ans,n-len(inn))
    print(ans)