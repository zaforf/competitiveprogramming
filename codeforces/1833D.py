for _ in range(int(input())):
	N = int(input())
	P = list(map(int,input().split()))
	r,E,l = 0,0,-1
	for i in range(1,N):
		if P[i]>E:
			r,E=i,P[i]
	if N==1:
		print(1)
	elif r==N-1:
		l=r
		while P[l-1]>P[0]:
			l-=1
		print(*P[r:l-1:-1]+P[:l])
	else:
		r-=1
		l=r
		while l-1>=0 and P[l-1]>P[0]:
			l-=1
		mid = [P[r]] if r==l else P[r:l-1:-1]
		print(*P[r+1:]+mid+P[:l])