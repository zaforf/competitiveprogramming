N = int(input())

def test(ndigits,base): 
	if base**(ndigits-1)>Q: return True,False
	s = (1-base**(ndigits))//(1-base)
	return s>=Q,s==Q

def findtrue(l,r,d):
	r+=1
	while (l<r):
		m = (l+r)//2
		if (x:=test(d,m))[0]:
			if x[1]:
				return m
			else:
				r=m
		else:
			l=m+1
	return -1

for i in range(N):
	Q = int(input())
	for j in range(3,61):
		if (s:=findtrue(2,int(1e18),j))!= -1:
			print("YES")
			break
	else:
		print("NO")