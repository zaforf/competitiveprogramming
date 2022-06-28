read = open("swap.in", "r").readline
write = open("swap.out", "w").write

n, k = map(int,read().split())
first = [x for x in range(n+1)]
second = [x for x in range(n+1)]
a,b = map(int,read().split())
for i in range(a,b+1):
    first[i] = b-(i-a)
a,b = map(int,read().split())
for i in range(a,b+1):
    second[i] = b-(i-a)
final = [0 for _ in range(n+1)]
for i in range(1,n+1):
    curr = i
    _=0
    while _<k:
        curr = second[first[curr]]
        _+=1
        if curr == i:
            _ = k-(k%(_))
            print("HI")
    final[curr]=i
for i in range(1,n+1):
    write(str(final[i])+"\n")