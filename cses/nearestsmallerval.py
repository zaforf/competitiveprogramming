n = int(input())
stack,i = [],1
for inp in map(int,input().split()):
    while(stack and stack[-1][0]>=inp):
        stack.pop()
    if stack: print(stack[-1][1],end=" ")
    else: print(0,end=" ")
    stack.append([inp,i])
    i += 1
