read = open("advent6.in", "r").readline

inp = read().strip()
ans = []
for i in range(len(inp)):
    if i>13 and inp[i-14] in ans:
        ans.remove(inp[i-14])
    ans.append(inp[i])
    if len(set(ans))==14:
        print(i+1)
        print(ans)
        break