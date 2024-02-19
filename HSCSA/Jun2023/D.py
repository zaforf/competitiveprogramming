N,M,K = map(int,input().split())
broken = K
ans = 0
for i in range(K):
	input()
	S = [*map(int,input().split())]
	for i in range(1,len(S)):
		if S[i]!=S[i-1]+1:
			broken+=1
			ans+=1
print(ans+broken-M)