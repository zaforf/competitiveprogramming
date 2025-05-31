def isp(s):
	return s==s[::-1]

for _ in range(int(input())):
	s = input()
	l = len(s)
	a = s[0]
	bi = 0
	for i in range(l):
		if s[i] != a:
			bi = i
			break
	if not isp(s):
		print("yes")
		print(1)
		print(s)
	elif not isp(s[:bi+1]) and not isp(s[bi+1:]):
		print("yes")
		print(2)
		print(s[:bi+1],s[bi+1:])
	elif not isp(s[:bi+2]) and not isp(s[bi+2:]):
		print("yes")
		print(2)
		print(s[:bi+2],s[bi+2:])
	else:
		print("no")
