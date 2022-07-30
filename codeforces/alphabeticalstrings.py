N = int(input())

for i in range(N):
    string = input()
    if string.count('a')!=1:
        print("NO")
        continue
    s1,s2 = [],[]
    for l in string:
        if l == 'a':
            break
        s1.append(l)
    for l in string[::-1]:
        if l == 'a':
            break
        s2.append(l)
    i = 98
    while True:
        if s1 and chr(i) == s1[-1]:
            s1.pop()
            i+=1
        elif s2 and chr(i) == s2[-1]:
            s2.pop()
            i+=1
        else:
            break
    print("NO" if s1 or s2 else "YES")