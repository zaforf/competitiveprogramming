N,K = map(int,input().split())

groups = [*set([-(int(input())//-12) for i in range(N)])]
groups.sort(reverse=True)
groups.append(0)


# print(groups)
N = len(groups)
diffs = [groups[i-1]-groups[i]-1 for i in range(1,N)]
diffs.sort()
# print(diffs)
print(12*(sum(diffs)-sum(diffs[-(K-1):])+len(groups)-1))
