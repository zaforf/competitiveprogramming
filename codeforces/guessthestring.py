def findlast(l,h):
    while (l<h):
        m = (l+h+1)//2
        print("? 2 "+str(l)+" "+str(m))
        if (input()=="1"):
            l=m
        else:
            h=m-1
    return l
ans = ""
n = int(input())
l=1
x = int(input("? 2 1 "+str(n)+"\n"))
while len(ans)<n:        
    last = findlast(l,n)
    let = input("? 1 "+str(last)+"\n")
    while len(ans)<last:
        ans+=let
    l=last+1
print("! "+str(ans))