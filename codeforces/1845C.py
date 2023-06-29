for _ in range(int(input())):
	db = input()
	M,l,r = int(input()),input(),input()
	ind = [0 for i in range(10)]
	c = -1
	done = False
	for i in range(M):
		for j in range(int(l[i]),int(r[i])+1):
			ind[j]=c+1
			while ind[j]<len(db) and db[ind[j]]!=str(j):
				ind[j]+=1
			if ind[j]==len(db): done=True;break
		for j in range(int(l[i]),int(r[i])+1):
			c = max(c,ind[j])
		if done: break
	if done: print("YES")
	else: print("NO")