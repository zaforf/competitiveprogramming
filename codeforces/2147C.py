def invalid(group):
	return '00' not in group and group.count('0') % 2 == 1


for _ in range(int(input())):
	n = int(input())
	s = input()
	groups = s.split("11")
	condition = any(invalid(group) for group in groups[1:-1])
	if len(groups) > 1:
		if groups[0] and groups[0][0] == '1':
			condition = condition or invalid(groups[0])
		if groups[-1] and groups[-1][-1] == '1':
			condition = condition or invalid(groups[-1])
	elif groups[0][0] == '1' and groups[0][-1] == '1':
		condition = condition or invalid(groups[0])
	if condition:
		print("NO")
	else:
		print("YES")