n = int(input())

ws = [input() for _ in range(n)]

def backtrack(ws):
	if len(ws) == 1:
		return (len(ws[0]), ws[0])

	res = (float('inf'), "")
	for i in range(len(ws)):
		for j in range(len(ws)):
			if i != j:
				a = ws[i]
				b = ws[j]
				# consider all merges
				merged = ""
				for k in range(1, min(len(a), len(b))+1):
					if a[-k:] == b[:k]:
						merged = a + b[k:]
					else:
						continue
					new_ws = [ws[x] for x in range(len(ws)) if x != i and x != j] + [merged]
					res = min(res, backtrack(new_ws))
	return res

ans = backtrack(ws)
if ans[0] == float('inf'):
	print(-1)
else:
	print(ans[1])