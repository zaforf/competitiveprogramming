

n = int(input())
string = input()
ans = 0
for i in range(n):
    r,l = 0,0
    while i-r>0 and string[i-r-1]!=string[i]:
        r+=1
    while i+l<n-1 and string[i+l+1]!=string[i]:
        l+=1
    ans+= (l+1)*(r+1)
    ans-=1
    if r>0:
        ans-=1
    if l>0:
        ans-=1
print(ans)