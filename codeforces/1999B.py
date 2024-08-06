for _ in range(int(input())):
	a,b,c,d = map(int,input().split())
	ans = 0
	if a>c and b>=d: ans+=1
	if a>d and b>=c: ans+=1
	if b>c and a>=d: ans+=1
	if b>d and a>=c: ans+=1
	if a==c and b>d: ans+=1
	if a==d and b>c: ans+=1
	if b==c and a>d: ans+=1
	if b==d and a>c: ans+=1
	print(ans)