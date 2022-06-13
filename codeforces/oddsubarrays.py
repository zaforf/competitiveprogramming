n = int(input())
for _ in range(n):
    x = int(input())
    stack = []
    ans = 0
    for inp in map(int,input().split()):
        if len(stack)>0 and stack[-1]>inp:
            while len(stack)>0:
                stack.pop()
            ans+=1
        else:
            stack.append(inp)
    print(ans)