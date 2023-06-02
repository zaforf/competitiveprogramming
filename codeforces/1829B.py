for _ in range(int(input())):
	N = int(input())
	A = list(map(int,input().split()))
	ans,cnt=(1 if A[0]==0 else 0),(1 if A[0]==0 else 0)
	for i in range(1,N):
		if A[i]==A[i-1] and A[i]==0:
			cnt+=1
		else:
			cnt=(1 if A[i]==0 else 0)
		ans=max(ans,cnt)
	print(ans)