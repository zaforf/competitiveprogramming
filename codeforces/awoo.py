n = int(input())
for _ in range(n):
    l = int(input())
    str1,str2 = input(),input()
    if str1==str2:
        print("YES")
        continue
    nstr1,nstr2 = "",""
    na1,na2=0,0
    nc1,nc2=0,0
    ok = True
    for i in range(l):
        if str1[i]!="b":
            nstr1+=str1[i]
        if str1[i]=="a":
            na1+=1
        elif str1[i]=="c":
            nc1+=1
        if str2[i]!="b":
            nstr2+=str2[i]
        if str2[i]=="a":
            na2+=1
        elif str2[i]=="c":
            nc2+=1
        if na2>na1:
            ok = False
            print("NO")
            break
        if nc1>nc2:
            ok = False
            print("NO")
            break
    if ok and nstr1==nstr2:
        print("YES")
    elif ok:
        print("NO")