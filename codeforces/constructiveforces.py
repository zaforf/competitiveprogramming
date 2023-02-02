T = int(input())
for _ in range(T):
    n = int(input())
    if n==3:
        print("NO")
    elif n%2==0:
        print("YES")
        print(*[[1,-1][i%2] for i in range(n)])
    else:
        print("YES")
        print(*[[n//2-1,-(n//2)][i%2] for i in range(n)])