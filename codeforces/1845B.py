for _ in range(int(input())):
	xa,ya = map(int,input().split())
	xb,yb = map(int,input().split())
	xc,yc = map(int,input().split())
	xb-=xa
	yb-=ya
	xc-=xa
	yc-=ya
	ans = 1
	if xb*xc>0:
		ans += min(abs(xb),abs(xc))
	if yb*yc>0:
		ans += min(abs(yb),abs(yc))
	print(ans)