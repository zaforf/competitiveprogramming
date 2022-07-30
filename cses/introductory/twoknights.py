precal = [0,6,28,96,252,550]

for i in range(1,int(input())+1):
    if i<7:
        print(precal[i-1])
        last = precal[i-1]
        last2 = precal[i-2]
        continue
    bothedge = ((4*i-4)*(4*i-5))//2-8 # if both knights are on edge
    oneedge = 4*(2*(2*(i-2)**2-5) + (i-6)*((i-2)**2-4) + (i-2)**2-2) # ones adj and almost adj to corner + rest + ones corner
    temp, last2 = last2, last
    last = temp+oneedge+bothedge
    print(last)
