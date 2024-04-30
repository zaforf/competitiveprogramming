x,MOD = 1,int(1e9)+7
for i in range(1,int(input())+1):
	x = (i*x + [1,-1][i%2]) % MOD
print(x)