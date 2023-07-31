for _ in range(int(input())):
	N = int(input())
	ANS = []
	C,INC = 1,1
	while (C<N):
		X = 0
		if (N-C-INC<=INC):
			X = N-C
		elif (N-C)//2<=2*INC:
			X = (N-C)//2
		else:
			X = 2*INC
		ANS.append(X-INC)
		INC = X
		C+=INC
	print(len(ANS))
	print(*ANS)