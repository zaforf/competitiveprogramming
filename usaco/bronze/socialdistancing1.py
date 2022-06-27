read = open("socdist1.in", "r").readline
write = open("socdist1.out", "w").write

n = int(read())
stalls = read().strip()
spaces=[]
currspace = 0
first = True
if "0"*n==stalls:
    write(str(n-1))
else:
    for i in range(len(stalls)):
        if stalls[i] == "0":
            currspace += 1
        else:
            if currspace != 0:
                if first:
                    spaces.append(2*currspace)    
                else:
                    spaces.append(currspace)
            first = False
            currspace = 0
    if currspace>0:
        spaces.append(2*currspace)
    spaces.sort()
    ans = 0
    if len(spaces)==1:
        write(str((spaces[0]-2)//3  +1))
    else:
        if (spaces[-1]-2)//3 > (spaces[-2]-1)//2:
            write(str(spaces[0]  +1))
        else:
            write(str(min(spaces[0]  +1,(spaces[-2]-1)//2  +1)))