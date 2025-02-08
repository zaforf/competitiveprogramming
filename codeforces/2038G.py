import sys

def write(*args):
	print(*args)
	sys.stdout.flush()

T = int(input())

for i in range(T):
	n = int(input())
	write(1,0)
	z = int(input())
	if z == n:
		write(0,1,0)
		input()
		continue
	elif z == 0:
		write(0,1,1)
		input()
		continue
	write(1,"00")
	g = int(input())
	z -= g
	write(1,"10")
	c = int(input())
	if c == z:
		write(0,1,1)
		input()
		continue
	else:
		write(0,1,0)
		input()
		continue