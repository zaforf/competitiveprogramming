print(33_333+2+33_333)

rej = set()

while True:
	q = int(input())
	if 0 <= q <= 100_000:
		if q == 0:
			print(1)
		elif q == 100_000:
			print(66668)
		elif q % 3 == 0:
			print(2 * q // 3 + 1)
		elif q % 3 == 2:
			if q-1 in rej:
				print(2 * (q+1) // 3)
			else:
				print(-1)
				rej.add(q)
		else:
			if q+1 in rej:
				print(2 * (q+2) // 3)
			else:
				print(-1)
				rej.add(q)
	else:
		p = 0
		while p <= 100_000:
			if p not in rej:
				print(p)
			p += 1
			if p % 3 == 2 and p-1 not in rej and p not in rej:
				p += 1
		break