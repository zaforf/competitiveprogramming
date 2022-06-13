n = int(input())

for _ in range(n):
    i = int(input())
    sum = 0
    e = set()
    for x in map(int,input().split()):
        e.add(x)
        sum+=x
    if sum//i in e and sum%i==0:
        print("YES")
    else:
        print("NO")