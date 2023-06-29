for _ in range(int(input())):
	N,K=map(int,input().split())
	arr = [0 for i in range(N)]
	arr[0],arr[-1]=1,1
	s = 0
	for i in range(N):
		s += arr[i]
		if (i+K)//K>s:
			arr[i]=1
			s+=1
	print(sum(arr))