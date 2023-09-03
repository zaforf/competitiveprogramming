N = int(input())
og = [*map(int,input().split())]
Q = int(input())

array = sorted(og)
def rank(n):
	r,l = 0,len(array)
	while r<l:
		m = (r+l)//2
		if array[m] < n:
			r = m+1
		else:
			l = m
	return l

dec = [array[0]]
for i in range(1,len(array)):
	dec.append(dec[-1]+i*array[i])

inc = [0 for i in range(len(array))]
inc[-1] = array[-1]
for i in range(len(array)-2,-1,-1):
	inc[i] = inc[i+1]+(i+2)*array[i]

up = [array[0]]
for i in range(1,len(array)): up.append(up[-1]+(i+1)*array[i])
down = [0 for i in range(len(array))]
down[-1] = len(array)*array[-1]
for i in range(len(array)-2,-1,-1): down[i]=down[i+1]+(i+1)*array[i]

index = {array[i]:i for i in range(len(og))}
for i in range(Q):
	a,b = map(int,input().split())
	a,b,t = index[og[a-1]], rank(b), b
	if b<=a:
		print(inc[b]-inc[a]+(b+1)*t+(up[b-1] if b>0 else 0)+(down[a+1] if a+1<len(array) else 0))
	else:
		print(dec[b-1]-dec[a]+b*t+(up[a-1] if a>0 else 0)+(down[b] if b<len(array) else 0))

