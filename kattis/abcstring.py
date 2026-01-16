s = input()

empty = 0
a_s, bs, cs = 0, 0, 0
abs, acs, bcs = 0, 0, 0

for ch in s:
	if ch == "A":
		if bcs > 0:
			bcs -= 1
			empty += 1
		elif bs > 0:
			bs -= 1
			abs += 1
		elif cs > 0:
			cs -= 1
			acs += 1
		elif empty > 0:
			empty -= 1
			a_s += 1
		else:
			a_s += 1
	elif ch == "B":
		if acs > 0:
			acs -= 1
			empty += 1
		elif a_s > 0:
			a_s -= 1
			abs += 1
		elif cs > 0:
			cs -= 1
			bcs += 1
		elif empty > 0:
			empty -= 1
			bs += 1
		else:
			bs += 1
	else:  # ch == "C"
		if abs > 0:
			abs -= 1
			empty += 1
		elif a_s > 0:
			a_s -= 1
			acs += 1
		elif bs > 0:
			bs -= 1
			bcs += 1
		elif empty > 0:
			empty -= 1
			cs += 1
		else:
			cs += 1
print(empty)