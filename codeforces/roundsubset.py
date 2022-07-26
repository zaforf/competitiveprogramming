n,p = map(int,input().split())
nums = []
for z in map(int,input().split()):
    x = z
    c2 = 0
    while x%2==0:
        x//=2
        c2+=1
    x = z
    c5 = 0
    while x%5==0:
        x//=5
        c5+=1
    nums.append([c2,c5])
if p==n:
    sum1,sum2=0,0
    for i in range(n):
        sum1 += nums[i][0]
        sum2 += nums[i][1]
    print(min(sum1,sum2))
else:
    aids = [[[-1 for i in range(1400)] for i in range(p+1)] for i in range(n+1)]
    ans = 0
    aids[0][0][0] = 0
    # first k numbers, taking j, with i powers of 5
    for k in range(n+1):
        for j in range(p+1):
            for i in range(61):
                if aids[k][j][i] == -1: continue
                if k+1 >= n+1: continue
                if j+1 < p+1:
                    aids[k+1][j+1][i+nums[k][1]] = max(aids[k+1][j+1][i+nums[k][1]],aids[k][j][i]+nums[k][0])
                aids[k+1][j][i] = max(aids[k+1][j][i],aids[k][j][i])
    for i in range(1400):
        if aids[n][p][i] != -1:
            ans = max(ans,min(i,aids[n][p][i]))
    print(ans)