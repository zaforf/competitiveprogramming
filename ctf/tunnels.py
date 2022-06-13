import random
import itertools

from regex import B

cnt = 0
def check(a,b):
    global cnt
    for i in range(8):
        if a[i]==b[i]:
            cnt+=1
            return
    return
e = 0

cnt = 0
b = 0
b+=1
cnt = 0
for i in range(200):
    a = []
    cur = random.randint(1,8)
    for j in range(8):
        a.append(cur)
        if cur == 1:
            cur = cur + 1
        elif cur == 8:
            cur = cur - 1
        else:
            cur = cur - 1 + 2 * random.randint(0,1)
    check(a,[4,7,2,5,5,2,7,4])
e+=b
print(e/1000)