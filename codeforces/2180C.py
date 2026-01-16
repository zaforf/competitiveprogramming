for _ in range(int(input())):
	n, k = map(int,input().split())

	tight = [0 for i in range(k)]
	loose = []

	bins = bin(n)[2:]
	b = len(bins)

	for i in range(b):
		if bins[i] == '1':
			if k % 2 == 0 and len(tight) > 0:
				loose.append(tight.pop())

			for j in range(len(tight)):
				tight[j] |= (1 << (b - i - 1))

			for j in range(len(loose) - (1 if k%2==0 else 0)):
				loose[j] |= (1 << (b - i - 1))
	
		
		elif bins[i] == '0':
			l = len(loose)
			for j in range(l - (1 if l%2==1 else 0)):
				loose[j] |= (1 << (b - i - 1))

	print(*tight,end=" ")
	print(*loose)