l = 1
h = 1000000
while (l<h):
    mid = (l+h+1)//2
    print(mid)
    if input() == "<":
        h = mid-1
    else:
        l = mid
print("! "+str(l))