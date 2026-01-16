r,c = 4,4

qs = [(2,2), (2,4), (4,2)]
for q in qs:
	print("?", q[0], q[1])
	res = int(input())
	if res == 1:
		r,c = q
		break


print("?", r-1, c)
res = int(input())
if res == 1:
	print("?", r-1, c-1)
	res = int(input())
	if res == 1:
		print("!", r-1, c-1)
	else:
		print("!", r-1, c)
else:
	print("?", r, c-1)
	res = int(input())
	if res == 1:
		print("!", r, c-1)
	else:
		print("!", r, c)

