for _ in range(int(input())):
	x = int(input())
	n = 1
	while (n<=x):
		n *= 10
	n //= 10
	if (n<100 or x//n > 1): print("NO")
	elif (x-n >= 2 and str(x) == "10"+str(x-n)): print("YES")
	else: print("NO")