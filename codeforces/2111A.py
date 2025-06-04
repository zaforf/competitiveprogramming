for _ in range(int(input())):
	n = int(input())
	x = 0
	ans = 0
	while x < n:
		ans += 2
		x = 2*x+1
	print(ans+1)