from collections import deque

N,M,K = map(int,input().split())

q = deque()
stack = [[int(1e9)+K,M]]
order = []

for i in range(N):
	order.append(tuple(map(int,input().split())))
order.sort(reverse=True)

# print(order)
ans = 0

for i in range(len(order)):
	weight,count = order[i]
	# print("trying",weight)
	while q and q[0][0]-weight >= K:
		stack.append(q.popleft())
	# print(stack)
	found = 0
	while stack and count>0:
		if stack[-1][1]>=count:
			stack[-1][1]-=count
			q.append([weight,count+found])
			ans += count+found
			count = 0
		else:
			count-=stack[-1][1]
			found += stack[-1][1]
			stack.pop()
	if not stack:
		q.append([weight,found])
		ans += found
	# print(stack,q)

print(ans)
