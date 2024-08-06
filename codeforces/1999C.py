for _ in range(int(input())):
	n,s,m = map(int,input().split())
	time = 0
	ints = [[*map(int,input().split())] for i in range(n)]	
	ints.append([m,0])
	ints.sort()
	ans = False
	for i in range(n+1):
		if time<ints[i][0] and ints[i][0]-time>=s: ans = True
		time = max(time,ints[i][1])
	print("YES" if ans else "NO")
