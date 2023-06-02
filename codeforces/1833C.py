for _ in range(int(input())):
	N=int(input())
	A=list(map(int,input().split()))
	print("YES" if min(A)%2==1 or sum(map(lambda i:i%2,A))==0 else "NO")
