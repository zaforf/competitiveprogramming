# n(n-1)/2

for _ in range(int(input())):
	N,K,Q=map(int,input().split())
	A = list(map(int,input().split()))
	ans = 0
	r = -1
	for i in range(N+1):
		if i==N or A[i]>Q:
			num = i-r-1
			r=i
			if num<K: continue
			if num==K:
				ans+=1
				continue
			if K==1:
				ans+=num*(num-1)//2+num
			else:
				ans+= num*(num-1)//2+num-(K-1)*num+K*(K-1)//2-(K-1)
	print(ans)