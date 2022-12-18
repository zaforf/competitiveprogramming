read = open("advent5.in", "r").readline

inp = read()
stacks = [[] for i in range((len(inp)+1)//4)]
while inp[1]!="1":
    for i in range(len(inp)):
        if inp[i]=="[":
            stacks[i//4].append(inp[i:i+4])
    inp = read()
stacks = [i[::-1] for i in stacks]
print(stacks)
inp = read()
while inp!="end":
    num = int(inp[5])+(int(inp[6])+9*int(inp[5]) if inp[6] in list(map(str,[1,2,3,4,5,6,7,8,9,0])) else 0)
    s = int(inp[17+(1 if inp[6] in list(map(str,[1,2,3,4,5,6,7,8,9,0])) else 0)])-1
    e = int(inp[12+(1 if inp[6] in list(map(str,[1,2,3,4,5,6,7,8,9,0])) else 0)])-1
    stacks[s].extend(stacks[e][len(stacks[e])-num:])
    for i in range(num):
        stacks[e].pop()
    inp = read()
print(stacks)
ans = ""
for i in stacks:
    ans+= i[-1][1]
print(ans)