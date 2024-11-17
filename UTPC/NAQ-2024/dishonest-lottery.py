n = int(input())

read = [map(int,input().split()) for i in range(10*n)]
nums = []
for row in read: nums.extend(row)
cnt = [0 for i in range(51)]
for i in nums:
	cnt[i]+=1

found = False
for i in range(51):
	if (cnt[i]>2*n):
		print(i,end=" ")
		found = True

if not found:
	print(-1)