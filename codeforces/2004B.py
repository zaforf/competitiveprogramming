for _ in range(int(input())):
	rooms = [0 for i in range(101)]
	a,b = map(int,input().split())
	for i in range(a,b+1):
		rooms[i] = 1
	c,d = map(int,input().split())
	for i in range(c,d+1):
		rooms[i] += 2
	if (c>b):
		print(1)
		continue
	if (a>d):
		print(1)
		continue
	ans = 0
	for i in range(1,101):
		if rooms[i]==2 and (rooms[i-1]&1>0): ans+=1
		elif rooms[i]==1 and (rooms[i-1]&2>0): ans += 1
		elif rooms[i]==3 and (rooms[i-1]>0): ans += 1
	print(ans)