T = int(input())

def calcsums(a,b):
    reta = [0 for i in range(p)]
    for i in range(p):
        for s in a:
            reta[i]+=int(s[i])
    retb = [0 for i in range(p)]
    for i in range(p):
        for s in b:
            retb[i]+=int(s[i])
    return reta,retb

for t in range(T):
    input()
    p,b = map(int,input().split())
    zs,ws = [],[]
    for i in range(b):
        st,r = input().split()
        if r=="0":
            zs.append(st)
        else:
            ws.append(st)
    sumz,sumw = calcsums(zs,ws)
    while True:
        ok = False
        for i in range(len(sumz)):
            if sumz[i]==0 and sumw[i]!=0:
                rem = set()
                for x in range(len(ws)):
                    if ws[x][i]=="1":
                        rem.add(ws[x])
                for r in rem:
                    ws.remove(r)
                sumz,sumw=calcsums(zs,ws)
                ok = True
                break
            elif sumw[i]==0 and sumz[i]!=0:
                rem = set()
                for x in range(len(zs)):
                    if zs[x][i]=="1":
                        rem.add(zs[x])
                for r in rem:
                    zs.remove(r)
                sumz,sumw=calcsums(zs,ws)
                ok = True
                break
            elif sumw[i]==len(ws) and sumz[i]!=len(zs):
                rem = set()
                for x in range(len(zs)):
                    if zs[x][i]=="0":
                        rem.add(zs[x])
                for r in rem:
                    zs.remove(r)
                sumz,sumw=calcsums(zs,ws)
                ok = True
                break
            elif sumz[i]==len(zs) and sumw[i]!=len(ws):
                rem = set()
                for x in range(len(ws)):
                    if ws[x][i]=="0":
                        rem.add(ws[x])
                for r in rem:
                    ws.remove(r)
                sumz,sumw=calcsums(zs,ws)
                ok = True
                break
        if len(ws)==0 or len(zs)==0:
            print("OK")
            break
        if not ok:
            print("LIE")
            break
                    

