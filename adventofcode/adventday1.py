read = open("advent1.in", "r").readline

ls = []
sum = 0
while True:
    inp = read().strip()
    if inp=="" or inp=="end":
        ls.append(sum)
        sum = 0
        if inp=="end":
            break
    else:
        sum+=int(inp)
ls.sort()
# part 1 print(ls[-1])
# part 2 print(ls[-1]+ls[-2]+ls[-3])


