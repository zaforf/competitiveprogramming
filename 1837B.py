for _ in range(int(input())):
	N = int(input())
	d = {"<":1,">":-1}
	ans,curr = 1,1
	s=input()
	for i in range(1,N):
		curr += (1 if s[i]==s[i-1] else -curr+1)
		ans=max(curr,ans)
	print(ans+1)
