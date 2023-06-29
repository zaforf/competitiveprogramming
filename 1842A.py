for _ in range(int(input())):
	A = input()
	B = sum(map(int,input().split()))
	C = sum(map(int,input().split()))
	if B==C:
		print("Draw")
	elif B>C:
		print("Tsondu")
	else:
		print("Tenzing")