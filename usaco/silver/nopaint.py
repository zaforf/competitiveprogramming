N,Q = map(int,input().split())
S = input()
S = [*map(lambda x:ord(x)-ord('A'),S)]

bef = []
aft = []

stack = []
cnt = [0 for i in range(26)]
for i in range(N):
	while stack and stack[-1]>S[i]:
		cnt[stack[-1]]-=1
		stack.pop()
	if cnt[S[i]] == 0:
		stack.append(S[i])
		cnt[S[i]]+=1
		bef.append(bef[-1]+1 if bef else 1)
	else:
		bef.append(bef[-1])


S = S[::-1]
stack = []
cnt = [0 for i in range(26)]
for i in range(N):
	while stack and stack[-1]>S[i]:
		cnt[stack[-1]]-=1
		stack.pop()
	if cnt[S[i]] == 0:
		stack.append(S[i])
		cnt[S[i]]+=1
		aft.append(aft[-1]+1 if aft else 1)
	else:
		aft.append(aft[-1])
aft = aft[::-1]

for i in range(Q):
	a,b=map(int,input().split())
	a-=2
	print((bef[a] if a>=0 else 0)+(aft[b] if b<N else 0))

