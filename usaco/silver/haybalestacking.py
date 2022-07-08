n,i = map(int,input().split())
line = [0 for i in range(n)]
for _ in range(i):
    s,e = map(int,input().split())
    line[s-1]+=1
    if e<n:
        line[e]-=1
vals = []
curr = 0
for i in line:
    curr+=i
    vals.append(curr)
vals.sort()
print(vals[len(vals)//2])
