ans = [(0,0),(1,0)] # sum, sum going left
r,cnt=2,2
for i in range(2,1000001):
	if i==r:
		ans.append((i*i+ans[i-cnt+1][0],i*i))
	elif i==cnt*(cnt+1)//2:
		ans.append((i*i+ans[i-cnt][0],i*i+ans[i-cnt][0]))
		r+=cnt
		cnt+=1
	else:
		ans.append((i*i+ans[i-cnt][1]+ans[i-cnt+1][0],i*i+ans[i-cnt][1]))
# IM A GENIUS IT ACTUALLY WORKS!!!!!

for _ in range(int(input())):
	print(ans[int(input())][0])