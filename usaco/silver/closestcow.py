K,M,N = map(int,input().split())

field = [] # center, value

for i in range(K):
	a,b = map(int,input().split())
	field.append((a,b))
for i in range(M):
	field.append((int(input()),-1))

field.sort()

ones = []

def findone(ents):
	lefts = []
	rights = []
	for i in range(len(ents)):
		lefts.append((ents[i][1]-ents[i][0],ents[i][2]))
		rights.append((ents[i][1]+ents[i][0],ents[i][2]))
	pre = []
	lx,rx = 0,0
	temp = 0
	for i in range(len(ents)):
		# left i
		while lx<len(lefts) and lefts[lx][0]<=lefts[i][0]:
			temp += lefts[lx][1]
			lx += 1
		while rx<len(rights) and rights[rx][0]<lefts[i][0]:
			temp -= rights[rx][1]
			rx += 1
		pre.append(temp)
		# right i
		while lx<len(lefts) and lefts[lx][0]<=rights[i][0]:
			temp += lefts[lx][1]
			lx += 1
		while rx<len(rights) and rights[rx][0]<rights[i][0]:
			temp -= rights[rx][1]
			rx += 1
		pre.append(temp)

	return max(pre)
s = 0
cntM = 0
ents = [] # (radius, center, value)
iM = 0
for i in range(len(field)):
	if field[i][1]==-1:
		for j in range(len(ents)):
			ents[j][0] = min(ents[j][0],field[i][0]-ents[j][1]-1)
		if cntM!=0 and s!=0:
			ret = findone(ents)
			ones.append(ret)
			ones.append(s-ret)
		if s!=0 and cntM==0: ones.append(s)
		s = 0
		iM = field[i][0]
		ents = []
		cntM += 1
	else: 
		s += field[i][1]
		ents.append([field[i][0]-iM-1,field[i][0],field[i][1]])
if s!=0: ones.append(s)

ones.sort(reverse=True)
print(sum(ones[:N]))
