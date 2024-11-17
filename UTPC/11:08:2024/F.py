n,w,b = map(int,input().split())

def extended_gcd(a, b):
    if a == 0:
        return b, 0, 1
    gcd, x1, y1 = extended_gcd(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return gcd, x, y

gcd, x, y = extended_gcd(w, b)


if gcd == 0:
    if (n==0):
        print("1")
    else:
        print("0")
elif n % gcd != 0:
    print("0")
elif (w == 0 or b == 0):
    print(1)
else:
    x *= n // gcd
    y *= n // gcd
    l = w*b // gcd
    if x<=0:
        x,y = y,x
        w,b = b,w
    dx, dy = (l//w), (l//b)

    # number to make both positive, where y is negative
    k = (-y+dy-1) // dy
    x -= dx*k
    y += dy*k
    print(x//dx+1)

