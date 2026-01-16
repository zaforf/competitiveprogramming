import sys
print(sys.executable)


from sortedcontainers import SortedSet

for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))

	unhandled = SortedSet()
	min_so_far = 1e9
	edges = []
	for v in a:
		while unhandled and unhandled[0] < v:
			pair = unhandled.pop(0)
			edges.append((pair, v))

		if min_so_far < v:
			edges.append((min_so_far, v))
		elif v != 1:
			unhandled.add(v)

	if unhandled:
		print("NO")
	else:
		print("YES")
		for u, v in edges:
			print(u, v)