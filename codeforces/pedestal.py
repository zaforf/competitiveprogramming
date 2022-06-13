n = int(input())
for i in range(n):
    x = int(input())
    if x%3==0:
        print(x//3,x//3+1,x//3-1)
    elif x%3 ==1:
        print(x//3,x//3+2,x//3-1)
    elif x%3 ==2:
        print(x//3+1,x//3+2,x//3-1)
