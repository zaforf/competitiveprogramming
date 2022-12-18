read = open("advent4.in", "r").readline

inp = read()
ans = 0
while inp!="end":
    a,b = int(inp[:inp.index("-")]),int(inp[inp.index("-")+1:inp.index(",")])
    inp = inp[inp.index(",")+1:]
    c,d = int(inp[:inp.index("-")]),int(inp[inp.index("-")+1:])
    print(a,b,c,d)
    if a>=c and a<=d:
        ans +=1
    elif c>=a and c<=b:
        ans += 1
    inp = read()
print(ans)