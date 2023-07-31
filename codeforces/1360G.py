from math import lcm	
for _ in range(int(input())):
	n,m,a,b = map(int,input().split())
	if (n*a!=m*b): print("NO");continue
	ans = [["1" if i<a else "0" for i in range(m)]]
	d = lcm(n,m)//n
	for i in range(n-1):
		ans.append(ans[-1][-d:]+ans[-1][:m-d])
	print("YES")
	print("\n".join(["".join(i) for i in ans])) 