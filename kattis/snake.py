n, m = map(int,input().split())

grid = [input() for _ in range(n)]

vis = {}
cells_vis = {}

for i in range(n):
	for j in range(m):
		if grid[i][j] != '.':
			cells_vis[(i,j)] = True

order = '0123456789abcdef'

inside = lambda x, y: 0 <= x < n and 0 <= y < m
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

snake = -1

for i in range(n):
	for j in range(m):
		if grid[i][j] == '0':
			snake = (i, j)
			curr = (i, j)
			lastdir = -1
			for d in range(4):
				nx, ny = curr[0] + dx[d], curr[1] + dy[d]
				if inside(nx, ny) and grid[nx][ny] == '1':
					snake += (d,)
					curr = (nx, ny)
					lastdir = d
					break

			p = 2
			while True:
				for d in range(4):
					if (d + 2) % 4 == lastdir:
						continue

					nx, ny = curr[0] + dx[d], curr[1] + dy[d]
					if inside(nx, ny) and p < 16 and grid[nx][ny] == order[p]:
						# encode into snake as 0,1,2 : straight, left, right
						if d == lastdir:
							snake += (0,)
						elif (d + 1) % 4 == lastdir:
							snake += (2,)
						else:
							snake += (1,)
						lastdir = d
						curr = (nx, ny)
						p += 1
						break
				else:
					break

			break
	if snake != -1:
		break

if len(snake) == 2:
	print(1)
	quit()

from collections import deque
q = deque([snake])
# print(snake)

while q:
	curr = q.popleft()
	if curr != snake and curr[:2] in cells_vis:
		print(1)
		quit()

	# consider going straight, left, right
	for turn in range(3):
		x, y, d = curr[0], curr[1], curr[2]
		if turn == 0:
			d = (d + 2) % 4
			nx, ny = x + dx[d], y + dy[d]
			ndir = (d + 2) % 4
		elif turn == 1:
			ndir = (d + 3) % 4
			nx, ny = x + dx[ndir], y + dy[ndir]
			ndir = (ndir + 2) % 4
		else:
			ndir = (d + 1) % 4
			nx, ny = x + dx[ndir], y + dy[ndir]
			ndir = (ndir + 2) % 4

		body = {}
		if inside(nx, ny):
			# iterate through the snake body and see if it collides
			start = curr[:2]
			body[start] = True
			d = curr[2]
			start = (start[0] + dx[d], start[1] + dy[d])
			body[start] = True
			for move in curr[3:-1]: # ignore the tail
				if move == 0:
					d = d
				elif move == 1:
					d = (d + 1) % 4
				else:
					d = (d + 3) % 4

				start = (start[0] + dx[d], start[1] + dy[d])
				body[start] = True

			if (nx, ny) not in body:
				old_ndir = curr[2]
				first_relative = -1
				if ndir == old_ndir:
					first_relative = 0
				elif (old_ndir + 1) % 4 == ndir:
					first_relative = 2
				else:
					first_relative = 1

				new_snake = (nx, ny, ndir) + (first_relative,) + curr[3:-1]
				if new_snake not in vis:
					vis[new_snake] = True
					q.append(new_snake)
print(0)


