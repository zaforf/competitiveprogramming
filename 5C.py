s = input()
stack = []
ans = [0 for i in range(len(s))]
for i,l in enumerate(s):
	if l=="(": stack.append(i)
	elif stack:
		p = stack.pop()
		ans[i]=ans[p-1]+i-p+1
print(max(ans),ans.count(max(ans)) if max(ans)>0 else 1)
