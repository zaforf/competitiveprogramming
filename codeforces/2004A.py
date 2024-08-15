for _ in range(int(input())):
	n = int(input())
	a = list(set(map(int,input().split())))
	if len(a)>2: print("NO")
	elif (len(a)==1): print("YES")
	elif abs(a[0]-a[1])>1: print("YES")
	else: print("NO")