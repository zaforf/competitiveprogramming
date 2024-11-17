from fractions import Fraction
from math import floor

def incube(x,y,z):
	i = floor(x/Fraction(1,3))
	j = floor(y/Fraction(1,3))
	k = floor(z/Fraction(1,3))
	if (i==3): i-=1
	if (j==3): j-=1
	if (k==3): k-=1
	return i%2 + j%2 + k%2 >= 2

L,xn,xd,yn,yd,zn,zd = map(int,input().split())

def solve():
	x = Fraction(xn,xd)
	y = Fraction(yn,yd)
	z = Fraction(zn,zd)
	for _ in range(L):
		good = False
		xdiv = x/Fraction(1,3)
		ydiv = y/Fraction(1,3)
		zdiv = z/Fraction(1,3)
		for i in range(2):
			for j in range(2):
				for k in range(2):
					newx,newy,newz = x,y,z
					if (i>0 and xdiv%1==0 and 0<xdiv<3):
						newx -= Fraction(1,3)
					if (j>0 and ydiv%1==0 and 0<ydiv<3):
						newy -= Fraction(1,3)
					if (j>0 and zdiv%1==0 and 0<zdiv<3):
						newz -= Fraction(1,3)
					good |= not incube(newx,newy,newz)
		if not good:
			print(0)
			return
		x = (x%Fraction(1,3))*3
		y = (y%Fraction(1,3))*3
		z = (z%Fraction(1,3))*3
	print(1)

solve()


