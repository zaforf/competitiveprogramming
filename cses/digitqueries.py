t = int(input())

for i in range(t):
    inp = int(input())
    if inp<10:
        print(inp)
        continue
    n,cnt,l = 9,1,0
    while inp>n:
        x=9*(10**cnt)
        cnt+=1
        l=n
        n+=x*cnt
    print(str(int("9"*(cnt-1))-(inp-l)//-cnt)[(inp-l-1)%cnt])
    
        