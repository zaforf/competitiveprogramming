n,k = map(int,input().split())

a = [int(input()) for _ in range(n)]
a.sort()
# compute rolling sum (mu - x_i)^2, k length

# mu^2 - 2*mu*x_i + x_i^2
s = sum(a[:k])
s_squared = sum(x**2 for x in a[:k])
mu = s / k
ans = mu**2 * k - 2 * mu * s + s_squared

for i in range(k, n):
	s += a[i] - a[i-k]
	s_squared += a[i]**2 - a[i-k]**2
	mu = s / k
	ans = min(ans, mu**2 * k - 2 * mu * s + s_squared)

print(ans)