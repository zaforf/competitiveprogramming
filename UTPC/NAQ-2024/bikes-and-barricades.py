n = int(input())
ans = 1000
for i in range(n):
	x1,y1,x2,y2 = map(int,input().split())
	if ((x2-x1) == 0): continue
	if ((x1 < 0 and x2 < 0) or (x2 > 0 and x1 > 0)): continue
	slope = (y2-y1)/(x2-x1)
	if (-slope*x1+y1 < 0): continue
	ans = min(ans,-slope*x1+y1)

if (ans > 999 or ans < 0):
	print(-1.0)
else:
	print(ans)