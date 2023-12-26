N,K = map(int,input().split())

times = [[*map(int,input().split())] for i in range(N)]
times = [[a,b] for a,b in times if b-a+1 >= 75]
times.sort()
# print(times)
x = 0
N = len(times)
ans = 0
if K<75:
	print(0)
	quit()
for i in range(N):
	tstart = times[i][1]-74
	# print(tstart)
	tfin = tstart+K
	while x+1<N and tfin-times[x][0]+1>=75:
		# print("can do",times[x])
		x+=1
	if x<N and tfin-times[x][0]+1 >= 75:
		x+=1
	# print(x-i)

	ans = max(ans,x-i)


print(ans)