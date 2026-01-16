n = int(input())

s = input()

p = 1
t = str(p)
for c in s:
	while True:
		if c in t:
			t = t[t.index(c)+1:]
			break
		else:
			p += 1
			t += str(p)
print(p)
