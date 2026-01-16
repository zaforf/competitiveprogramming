for _ in range(int(input())):
	n = int(input())
	a = [*map(int,input().split())]
	c = a.count(1)

	if c == n:
		if c % 2 == 1:
			print("Alice")
		else:
			print("Bob")
	elif c % 2 == 1:
		print("Bob")
	else:
		print("Alice")
