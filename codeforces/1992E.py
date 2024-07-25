naMAX = 1000001
bMAX = 10001
for i in range(int(input())):
	n = int(input())
	x = n
	strs = []
	while (x<naMAX):
		x *= 10**len(str(n))
		x += n
	x = str(x)
	strs = [x[:i] for i in range(1,8) if int(x[:i])<naMAX]
	ans = []
	for b in range(1,bMAX):
		for st in strs:
			if (len(st)+b)%(len(str(n)))!=0: continue
			a = (len(st)+b)//len(str(n))
			if(a>10000): continue
			if (int(st)==n*a-b):
				ans.append((a,b))

	print(len(ans))
	for i,j in ans: print(i,j)