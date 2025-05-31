for _ in range(int(input())):
	s = input()
	c = 0
	for i in range(len(s)):
		if s[i] == '(':
			c += 1
		else:
			c -= 1
		if c == 0 and i < len(s) - 1:
			print("YES")
			break
	else:
		print("NO")
