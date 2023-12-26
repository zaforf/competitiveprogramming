T,C = map(int,input().split())

Ts = set([*map(int,input().split())])
C = input()
res = [set(),set(),set(),set(),set()] # [-2,-1,0,1,2], extra points, set hit
loc = [0 for i in range(len(C))]


p = 0
nochange = 0
hit = set()
for i in range(len(C)):
	if C[i]=="L":
		p-=1
	if C[i]=="R":
		p+=1
	if C[i]=="F" and p in Ts and not p in hit:
		hit.add(p)
		nochange+=1
	loc[i] = p
	# hitat.append(set(hit))


ans = 0

if loc[-1] in Ts and C[-1]=="F":
	res[2].add(loc[-1])
	ans = len(hit.union(res[2]))
if C[-1]=="F":
	if loc[-1]-2 in Ts:
		res[0].add(loc[-1]-2)
	if loc[-1]-1 in Ts:
		res[1].add(loc[-1]-1)
	if loc[-1]+1 in Ts:
		res[3].add(loc[-1]+1)
	if loc[-1]+2 in Ts:
		res[4].add(loc[-1]+2)


for i in range(len(C)-2,-1,-1):
	if C[i]=="R":
		# change to L, shift left -2
		ans = max(ans,len(hit.union(res[0])))
		# change to F, shift left -1
		ans = max(ans,len(hit.union(res[1]))+(1 if loc[i] in Ts and (not loc[i] in hit) and (not loc[i] in res[1]) else 0))
	if C[i]=="L":
		# change to R, shift right +2
		ans = max(ans,len(hit.union(res[4])))
		# change to F, shift right +1
		ans = max(ans,len(hit.union(res[3]))+(1 if loc[i] in Ts and (not loc[i] in hit) and (not loc[i] in res[3]) else 0))
	if C[i]=="F":
		# change to R, shift to right+1
		ans = max(ans,len(hit.union(res[3]))+(-1 if loc[i] in Ts and not loc[i] in res[3] else 0))
		# change to L, shift to left-1
		ans = max(ans,len(hit.union(res[1]))+(-1 if loc[i] in Ts and not loc[i] in res[1] else 0))


		if loc[i]-2 in Ts and not loc[i]-2 in res[0]:
			res[0].add(loc[i]-2)
		if loc[i]-1 in Ts and not loc[i]-1 in res[1]:
			res[1].add(loc[i]-1)
		if loc[i]+1 in Ts and not loc[i]+1 in res[3]:
			res[3].add(loc[i]+1)
		if loc[i]+2 in Ts and not loc[i]+2 in res[4]:
			res[4].add(loc[i]+2)
		if loc[i] in hit: hit.remove(loc[i])
	# print(i,res,ans,hitat[i])

# print("---")
# for r in res:
# 	print(r)
print(ans)