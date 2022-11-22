read = open("moobuzz.in", "r").readline
write = open("moobuzz.out", "w").write

n = int(read())

hi,lo = 1874999999,0
while lo<hi:
    med = (hi+lo)//2
    moos = (med//3)+(med//5)-(med//15)
    if med-moos<n:
        lo = med+1
    else:
        hi = med
write(str(lo))

