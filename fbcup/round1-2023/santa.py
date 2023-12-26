import sys
sys.stdin = open("santa.in", "r")
sys.stdout = open("santa.out", "w")

T = int(input())

for i in range(T):
	n = int(input())
	l = [*map(int,input().split())]
	l.sort()
	ans = 0
	if n==5:
		minx = (l[0]+l[2])/2
		maxx = (l[-1]+l[-2])/2
		ans = max(ans,maxx-minx)
		minx = (l[0]+l[1])/2
		maxx = (l[-1]+l[-3])/2
		ans = max(ans,maxx-minx)
		print(f"Case #{i+1}:",ans)
	else:
		minx = (l[0]+l[1])/2
		maxx = (l[-1]+l[-2])/2
		ans = maxx-minx
		if ans%1==0.0:
			ans = int(ans)
		print(f"Case #{i+1}:",ans)