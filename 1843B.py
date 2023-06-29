for _ in range(int(input())):
	N = int(input())
	A = [*map(int,input().split())]
	cnt = 0
	on = False
	for i in range(N):
		if A[i]==0: continue
		if A[i]<=0 and not on:
			on = True
			cnt+=1
		elif A[i]>0: on = False
	print(sum(map(abs,A)),cnt)
