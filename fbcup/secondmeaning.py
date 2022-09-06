read = open("second_meaning_input.txt", "r").readline
write = open("smeaning.out", "w").write

t = int(read())
for i in range(t):
    n = int(read())
    n-=1
    f = read().strip()
    d = (0 if len(f)%2==0 else 1)
    write("Case #"+str(i+1)+":\n")
    x = 1
    if f=="."*len(f):
        while(n>0):
            write("-"*(2*x+d)+".\n")
            x+=1
            n-=1
    else:
        while(n>0):
            write("."*(2*x+d)+"-\n")
            x+=1
            n-=1