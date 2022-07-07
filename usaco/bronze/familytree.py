read = open("family.in", "r").readline
write = open("family.out", "w").write

n,s,e = read().split()
n = int(n)
pedigree = {}
for _ in range(n):
    x,y = read().split()
    if y in pedigree:
        pedigree[y]=x
    else:
        pedigree[y]=x
xlist,ylist = [],[]
a = s
while a in pedigree:
    a = pedigree[a]
    xlist.append(a)
a = e
while a in pedigree:
    a = pedigree[a]
    ylist.append(a)
ok = False
for i in range(len(xlist)):
    for i2 in range(len(ylist)):
        if xlist[i]==ylist[i2]:
            ok = True
            break
    if ok:
        break
if s in ylist:
    z = ylist.index(s)
    print(z)
    write(str(s)+" is the "+"great-"*(z-1)+["mother","grand-mother"][z>0]+" of "+str(e))
elif e in xlist:
    z = xlist.index(e)
    write(str(e)+" is the "+"great-"*(z-1)+["mother","grand-mother"][z>0]+" of "+str(s))
else:
    try:
        if xlist[i]!=ylist[i2]:
            write("NOT RELATED")
        elif i>0 and i2>0:
            write("COUSINS")
        elif i==i2 and i==0:
            write("SIBLINGS")
        else:
            if i>i2:
                write(str(e)+" is the "+"great-"*(abs(i-i2)-1)+"aunt of "+str(s))
            else:
                write(str(s)+" is the "+"great-"*(abs(i-i2)-1)+"aunt of "+str(e))
    except NameError:
        write("NOT RELATED")