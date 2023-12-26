import sys
sys.stdin = open("sum.in", "r")
sys.stdout = open("sum.out", "w")

from math import sqrt
T = int(input())

for x in range(T):
	n = int(input())
	ls = {}
	for i in range(2,int(sqrt(n))+1):
		if n%i==0:
			while n%i==0:
				n//=i
				ls[i] = ls.get(i,0)+1
	if n!=1:
		ls[n]=1
		n//=n
	sums = 0
	for k in ls:
		sums += k*ls[k]
	if sums>41:
		print(f"Case #{x+1}:",-1)
		continue
	else:
		ans = []
		for k in ls:
			for j in range(ls[k]):
				ans.append(k)
		if sum(ans)<41:
			ans.extend([1]*(41-sum(ans)))
		print(f"Case #{x+1}:",len(ans),*ans)

