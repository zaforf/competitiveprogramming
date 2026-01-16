dig = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
mp = {dig[i]:i for i in range(62)}

for _ in range(int(input())):
	a = input()
	b = input()
	if b < a:
		a, b = b, a

	a = "0"*(len(b)-len(a)) + a
	b = "0"*(len(a)-len(b)) + b
	i = 0
	while a[i] == b[i]:
		i += 1

	# find if a or b bigger
	if mp[a[i]] < mp[b[i]]:
		print("YES")
	else:
		print("NO")
