n = int(input())
v = int(input(), 2)
ans, x = v, v
for i in range(30):
	ans = max(ans, v | x)
	x //= 2
print(bin(ans)[2:])