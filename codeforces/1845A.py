for _ in range(int(input())):
	N,K,X = map(int,input().split())
	if N%2==1 and K<3 and X==1 or (K==1):
		print("NO")
	else:
		print("YES")
		if X==1:
			if N%2==1:
				print(N//2)
				print("2 "*(N//2-1)+"3")
			else:
				print(N//2)
				print("2 "*(N//2))
		else:
			print(N)
			print("1 "*(N-1)+"1")