def is_palindrome(s):
	return s == s[::-1]

for _ in range(int(input())):
	s = input()
	l = len(s)
	if not is_palindrome(s):
		print("YES")
		print(1)
		print(s)
	else:
		a = s[0]
		bi = 0
		for i in range(l):
			if s[i] != a:
				bi = i
				break
		if not is_palindrome(s[:2*bi]) and not is_palindrome(s[2*bi:]):
			print("YES")
			print(2)
			print(s[:2*bi],s[2*bi:])
		else:
			if len(set(s)) > 1:
				print(s)
			print("NO")