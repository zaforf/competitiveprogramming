n = int(input())
for _ in range(n):
    a,b = map(int,input().split())
    ans = sum((map(int,input().split())))
    print(max(0,ans-b))