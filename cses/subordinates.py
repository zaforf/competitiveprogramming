import sys
sys.setrecursionlimit(200000)

n = int(input())
adj = [set() for _ in range(n+1)]
for i,v in enumerate(map(int,input().split())):
    adj[v].add(i+2)
 
dict = {}
def count(x):
    r = 0
    if x in dict:
        return dict[x]
    for nb in adj[x]:
        r += count(nb)
        r += 1
    dict[x] = r
    return r
 
for i in range(n):
    print(count(i+1),end=" ")