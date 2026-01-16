a = input()
b = input()

fa, fb = float(a), float(b)
ta, tb = tuple(map(int, a.split('.'))), tuple(map(int, b.split('.')))

if ta > tb and fa > fb:
	print(a)
elif ta < tb and fa < fb:
	print(b)
else:
	print(-1)