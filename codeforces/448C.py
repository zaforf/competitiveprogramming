N = int(input())
A = [*map(int,input().split())]

def paint(l,r):
	global A
	vert = r-l
	hmin = min(A[l:r])
	for i in range(l,r): A[i]=A[i]-hmin
	x,y = l,l
	if max(A[l:r])>0:
		while x<r:
			while y+1<r and A[y]>0: y+=1
			while x+1<r and A[x]==0: x+=1
			if y+1==r and A[y]>0: y+=1
			hmin += paint(x,y)
			x,y=y,y+1
	return min(vert,hmin)

print(paint(0,N))
