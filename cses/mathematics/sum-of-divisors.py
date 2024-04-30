n = int(input())
MOD = int(1e9)+7

def s(n): return n*(n+1)//2 % MOD

x = 1
while x*x <= n: x += 1
x-=1

ans = 0
i = 1
while i*i <= n:
	ans += n - n%i % MOD # left side
	ans += s(n//i)-s(x) % MOD # right side
	ans %= MOD
	i += 1

print(ans)