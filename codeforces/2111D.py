for _ in range(int(input())):
	n, m = map(int, input().split())
	classes = [*map(int, input().split())]
	classes.sort()
	ans = []
	for i in range(m):
		small = classes[i]
		big = classes[-i-1]
		ans.append([small,big,small,big,small,big])
		ans.append([big,small,big,small,big,small])
	for i in range(n):
		print(*ans[i])