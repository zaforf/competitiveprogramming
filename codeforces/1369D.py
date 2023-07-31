MOD = int(1e9)+7
ans = [-1,(False,0),(False,0)]
for i in range(3,2*int(1e6)+1):
	r,n = False,0
	a,b = ans[i-2];r|=a;n+=b
	a,b = ans[i-1];r|=a;n+=b
	a,b = ans[i-2];r|=a;n+=b
	ans.append((not r,(n+(not r))%MOD))

for _ in range(int(input())):
	print(ans[int(input())][-1]*4%MOD)