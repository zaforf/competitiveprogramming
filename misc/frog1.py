# https://atcoder.jp/contests/dp/tasks/dp_a

N = int(input())
stones = list(map(int,input().split()))
cost = [0 for i in range(N)]

for i in range(1,N):
    cost[i] = cost[i-1]+abs(stones[i]-stones[i-1])
    if i>1: cost[i] = min(cost[i],cost[i-2]+abs(stones[i]-stones[i-2]))

print(cost[-1])