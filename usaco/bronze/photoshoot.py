longitud = int(input())
cadena = input()
ans = 0
while True:
    ind = 0
    des = 0
    cut = -1
    for i in range(longitud):
        if cadena[i]=="G":
            if i%2==0:
                ind+=1
            else:
                ind-=1
        if i%2==1 and ind>des:
            des=ind
            cut=i
        if ind>0:
            2
    if cut!=-1:
        ans+=1
    else:
        break
    cadena = cadena[cut::-1]+cadena[cut+1:]
    print(cadena)
print(ans)
