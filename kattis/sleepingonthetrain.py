n,t,a,b = map(int, input().split())

l = [a] + [i+0.5 for i in map(int, input().split())] + [b]

ans = 0
d = 1 if l[1] > a else -1
for i in range(2, t+2):
	if (l[i] - l[i-1]) * d < 0:
		d *= -1
		ans += 1

print(ans)