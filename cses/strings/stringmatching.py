# import sys

# sys.stdin = open("std.in", "r")
# sys.stdout = open("std.out", "w")

def zalgo(st):
    z = [0 for i in range(len(st))]
    l,r=0,0
    for k in range(1,len(st)):
        if k>r:
            # extend r for first z box
            l,r=k,k
            while (r<len(st) and st[r]==st[r-l]):
                r+=1
            z[k]=r-l
            r-=1
        else:
            # if r is far enough that k<=r
            if (z[k-l]<r-k+1):
                # if bound based on referencing prefix of string is not past r, then just copy
                z[k]=z[k-l]
            else:
                # otherwise recalculate z box, with a new l and extending r
                l=k
                while (r<len(st) and st[r]==st[r-l]):
                    r+=1
                z[k]=r-l
                r-=1
    return z
b,a=input(),input()
z = zalgo(a+"$"+b)
# print(z)
print(sum([i==len(a) for i in z]))