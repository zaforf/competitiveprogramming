for _ in range(int(input())):
	n = int(input())
	points = [tuple(map(int, input().split())) for _ in range(n)]

	print("?","R",int(1e9))
	print("?","R",int(1e9))
	print("?","U",int(1e9))
	print("?","U",int(1e9))

	dist = 0
	for _ in range(4):
		dist = int(input())

	lx,ly = int(1e9), int(1e9)
	min_dist = 1e10
	for x,y in points:
		min_dist = min(min_dist, abs(lx-x) + abs(ly-y))
	x_plus_y = dist - min_dist # x + y

	print("?","L",int(1e9))
	print("?","L",int(1e9))
	print("?","L",int(1e9))
	print("?","L",int(1e9))

	lx,ly = -int(1e9), int(1e9)
	min_dist = 1e10
	for x,y in points:
		min_dist = min(min_dist, abs(lx - x) + abs(ly - y))

	for _ in range(4):
		dist = int(input())
	y_minus_x = dist - min_dist # 1e9 - x + y

	y = (x_plus_y + y_minus_x - int(2e9)) // 2
	x = x_plus_y - y
	print("!", x-int(1e9), y-int(1e9))
