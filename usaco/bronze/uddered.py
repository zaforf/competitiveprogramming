bet = input()
moo = input()
last = -1
ans = 1
for letter in moo:
    x = bet.index(letter)
    if x<=last:
        ans+=1
    last=x

print(ans)