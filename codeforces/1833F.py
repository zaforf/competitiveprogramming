MOD = int(1e9+7)
fact = [1]
for i in range(1,int(2*10e5+1)):
	fact.append(i*fact[-1]%MOD)

for _ in range(int(input())):
	N,M = map(int,input().split())
	S = list(map(int,input().split()))
	S.sort()
	r,ans=0,0
	print(S)
	cnt = {}
	for i in range(N-M+1):
		while r+1<N and S[r+1]-S[i]<M:
			if S[r+1]==S[r]: cnt[S[r]]=1+(cnt[S[r]] if S[r] in cnt else 1)
			r+=1
		c = r-i+1
		calc = fact[c-1]/fact[M-1]/fact[c-M]
		if cnt:
			for k in cnt:
				calc/=min(fact[M],fact[cnt[k]])
		ans +=calc 
		print(calc)
		if S[i] in cnt:
			cnt.pop(S[i])
	print(ans)

