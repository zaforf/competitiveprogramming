n = int(input())

w, b = 0,0
m = [1,1,1,0,1,1,0]

l = 0
i = -1
while True:
	l += 4
	w += 1
	if (i>=0): l -= m[i%7]
	i += 1
	if (l>=n): break
	b += m[i%7]
	l += m[i%7]
	if (l>=n): break
	
if (l>n):
	print(-1)
else:	
	print(w,b)