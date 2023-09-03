import sys
sys.stdin = open("mountains.in", "r")
sys.stdout = open("mountains.out", "w")

N = int(input())

diags = {}
for _ in range(N):
	a,b = map(int,input().split())
	diags[a-b] = max(diags.get(a-b,0),a+b)

mounts = list(diags.keys())
mounts.sort()
mounts = [(i,diags[i]) for i in mounts]

maxheight = mounts[0][1]
ans = 1
for i in range(1,len(mounts)):
	if mounts[i][1]>maxheight:
		ans+=1
	maxheight = max(maxheight,mounts[i][1])
print(ans)