ranom = {"A":1,"B":10,"C":100,"D":1000,"E":10000}

def eval(s):
	maxr,ans,l = "",0,len(s)
	for i in range(1,l+1):
		i=l-i
		maxr = max(maxr,s[i])
		ans += [1,-1][s[i]<maxr]*ranom[s[i]]
	return ans

def replacechar(s,i,c):
	return s[:i]+c+s[i+1:]

for _ in range(int(input())):
	s = input()
	l = len(s)
	cands = []
	for x in ["A","B","C","D","E"]:
		for y in ["A","B","C","D","E"]:
			if not x in s:
				continue
			cands.append(replacechar(s,s.find(x),y))
			cands.append(replacechar(s,s.rfind(x),y))
	print(max(map(eval,cands)))