a = input()
b = input()

a = "0"*(len(b)-len(a)) + a

i = 0
s = 0
while i < len(a) and a[i] == b[i]:
	if a[i]=='1':
		s += 1
	i += 1
print(s+len(b)-i)
