n = int(input())

def check(med,list):
    stack = sorted(list)
    for i in range(med,0,-1):
        while stack and stack[-1]>i:
            stack.pop()
        if not stack:
            return False
        stack.pop()
        if stack:
            stack.pop(0)
    return True

def binsearch(x,list):
    l,h = 0,x
    while l<h:
        med = (l+h+1)//2
        if check(med,list):
            l=med
        else:
            h=med-1
    return l

for _ in range(n):
    i = int(input())
    inp = list(map(int,input().split()))
    print(binsearch(i,inp))