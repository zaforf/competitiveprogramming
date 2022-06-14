psbl = []
for i in range(0,10):
    for i2 in range(i,10):
        for i3 in range(i2,10):
            if ((i+i2+i3)%10 == 3):
                psbl.append([i,i2,i3])

def check(x):
    global dict
    e = {}
    for num in x:
        if num in e:
            e[num]+=1
        else:
            e[num]=1
    for key in e:
        if key not in dict:
            return False
        if key in dict and e[key]>dict[key]:
            return False
    return True

n = int(input())
for _ in range(n):
    i = int(input())
    dict = {}
    for num in map(int,input().split()):
        if num%10 in dict:
            dict[num%10]+=1
        else:
            dict[num%10]=1
    works = False
    for ps in psbl:
        works = check(ps)
        if works:
            break
    if works:
        print("YES")
    else:
        print("NO")