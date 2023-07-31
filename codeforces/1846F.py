for _ in range(int(input())):
	N = int(input())
	A = [*map(int,input().split())]
	count = {i:A.count(i) for i in set(A)}
	print("- 0")
	A = [*map(int,input().split())]
	found = -1
	for i in A: 
		if A.count(i)>count.get(i,0): 
			found=i
			break
	else:
		print("- 0")
		A = [*map(int,input().split())]
		for i in A:
			if A.count(i)>count.get(i,0):
				found=i
				break
	print(f"- {len(A)-A.count(found)} "+" ".join([str(i+1) for i in range(len(A)) if A[i]!=found]))
	A = [*map(int,input().split())]
	for i in range(len(A)):
		if A[i]!=found:
			print(f"! {i+1}")
			break
	else:
		print("- 0")
		A = [*map(int,input().split())]
		for i in range(len(A)):
			if A[i]!=found:
				print(f"! {i+1}")
				break
		else:
			print("- 0")
			A = [*map(int,input().split())]
			for i in range(len(A)):
				if A[i]!=found:
					print(f"! {i+1}")
					break