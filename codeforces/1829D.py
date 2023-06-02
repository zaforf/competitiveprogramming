pow2 = [1]
i = 0
exp2 = {1:0}
while pow2[-1]<int(1e7):
	pow2.append(2*pow2[-1])
	i+=1
	exp2[pow2[-1]]=i
pow2 = set(pow2)

for _ in range(int(input())):
	A,B = map(int,input().split())
	cnt=0
	done=False
	while A>0:
		if B%A==0 and B//A in pow2 and cnt>=exp2[B//A]:
			print("YES")
			done=True
			break
		if A%3!=0:
			done=True
			print("NO")
			break
		A//=3
		cnt+=1
	if not done:
		print("NO")