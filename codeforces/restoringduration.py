n = int(input())

for i in range(n):
    x = int(input())
    inp = list(map(int,input().split()))
    oth = list(map(int,input().split()))
    fin = 0
    for e in range(x):
        if e>0:
            inp[e] = max(inp[e],fin)
        print(oth[e]-inp[e],end=" ")  
        fin = oth[e]  
    print()