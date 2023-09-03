import sys
sys.stdin = open("herding.in", "r")
sys.stdout = open("herding.out", "w")

N = int(input())
cows = [int(input()) for i in range(N)]
cows.sort()

r = 0
minans = N-1
for l in range(len(cows)):
	while r+1<N and cows[r+1]-cows[l]<=N-1:
		r+=1
	minans = min(minans,N-(r-l+1))
if (cows[-1]-cows[-2]>2 and cows[-2]-cows[0]==N-2) or (cows[1]-cows[0]>2 and cows[-1]-cows[1]==N-2):
	print(2)
else:
	print(minans)

maxans = 0
for i in range(1,len(cows)):
	if N==3:
		maxans = max(maxans,cows[i]-cows[i-1]-1)
	else:
		maxans += cows[i]-cows[i-1]-1
if N!=3:
	maxans -= min(cows[1]-cows[0]-1,cows[-1]-cows[-2]-1)
print(maxans)