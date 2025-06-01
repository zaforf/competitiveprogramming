for _ in range(int(input())):
	n,k = map(int, input().split())
	s = input()
	c0 = s.count('0')
	c1 = s.count('1')
	if abs(c0-c1)//2 <= k <= c0//2 + c1//2 and (abs(c0-c1)//2 %2 == k % 2):
		print('YES')
	else:
		print('NO')