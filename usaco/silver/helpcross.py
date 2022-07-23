from math import inf
from queue import PriorityQueue

read = open("helpcross.in", "r").readline
write = open("helpcross.out", "w").write

ncow,nchick = map(int,read().split())
cows,chicks = [],[]
all = []
for i in range(ncow):
    all.append([int(read().strip()),inf])
for i in range(nchick):
    all.append((list(map(int,read().split()))))
all.sort()
stack = PriorityQueue()
ans = 0
for i in all:
    if i[1] is not inf:
        stack.put(i[1])
    else:
        while not stack.empty() and stack.queue[0] < i[0]: stack.get()
        if not stack.empty() and stack.queue[0] >= i[0]:
            stack.get()
            ans += 1
write(str(ans))