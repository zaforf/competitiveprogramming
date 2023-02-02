T = int(input())
for _ in range(T):
    n = int(input())
    vals = input()
    c = int(vals[0])
    ans=[]
    for i in range(1,len(vals)):
        ans.append(["+","-"][c%2])
        c+=int(vals[i])
    print("".join(ans))
