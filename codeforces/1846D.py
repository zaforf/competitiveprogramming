for _ in range(int(input())):
	N,W,H = map(int,input().split())
	B = [*map(int,input().split())]
	B.sort()
	area = 0
	for i in range(N-1):
		d = B[i+1]-B[i]
		if (d>=H):
			area+= W*H/2
		else:
			b2 = W-d*W/H
			area+=(b2+W)/2*d
	area += W*H/2
	print(area)