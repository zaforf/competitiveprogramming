for _ in range(int(input())):
	N,K = map(int,input().split())
	A = [*map(int,input().split())]
	diffs = []
	ans = 0
	for i in range(1,N):
		diffs.append(abs(A[i]-A[i-1]))
		ans += abs(A[i]-A[i-1])
	diffs.sort(reverse=True)
	print(ans-sum(diffs[:K-1]))