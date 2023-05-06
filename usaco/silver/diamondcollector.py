import sys
sys.stdin = open('diamond.in', 'r')
sys.stdout = open('diamond.out','w')

N,K = map(int,input().split())
vals = [int(input()) for i in range(N)]
vals.sort()
heads = []
j = 0
for i in range(len(vals)):
    while j+1<N and vals[j+1]-vals[i]<=K:
        j+=1
    heads.append(j-i+1)
ans = 0
maxafter = [0 for i in range(N)]
curr = 0
for i in range(len(vals)-1,-1,-1):
    curr = max(curr,heads[i])
    maxafter[i] = curr
for i in range(len(vals)):
    if i+heads[i]<N:
        ans = max(ans,heads[i]+maxafter[i+heads[i]])
print(ans)