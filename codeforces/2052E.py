s = input()

s = s.replace("+"," + ").replace("-"," - ").replace("="," == ")

def eval_s(s):
	for l in s:
		if (type(l) == list
		and int("".join(l)) == 0
		and l != ["0"]): return False
	try:
		return eval("".join(["".join(i) for i in s]))
	except SyntaxError:
		return False


def try_all(s,dig):
	n = len(s)
	for i in range(n):
		if type(s[i]) != list: continue
		l = len(s[i])
		if l==10: continue
		for j in range(l+1):
			s[i].insert(j,dig)
			if eval_s(s):
				print("".join(["".join(i) for i in s]).replace("==","="))
				return True
			s[i].pop(j)

def solve(s):
	s = [list(i) if i.isdigit() else i for i in s.split()]
	if eval_s(s):
		print("Correct")
		return

	n = len(s)
	for i in range(n):
		if type(s[i]) != list: continue
		l = len(s[i])
		if l == 1: continue
		for j in range(l):
			dig = s[i].pop(j)
			if try_all(s,dig):
				return
			s[i].insert(j,dig)

	print("Impossible")

solve(s)