import math

def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

s = 0
p = 0
for i in range(2,100001):
    s += i
    x = -(s//-i)
    if is_prime(x): p += 1
    if p < i//3 - 1:
        print(p,i,i//3-1)