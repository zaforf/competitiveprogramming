for i in range(int(input())):
    a,b = map(int,input().split())
    x,y = a-(a+b)/3,2*(a+b)/3-a
    s = (2*x+y,2*y+x)
    print("YES" if ((a,b)==s or (b,a)==s) and abs(int(x))==x and abs(int(y))==y else "NO")
