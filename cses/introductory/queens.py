grid = []
for i in range(8):
    grid.append(input())
cnt = 0

def gennext(row,used):
    if row==8:
        return 1
    res = 0
    for i in range(8):
        if i not in used and grid[row][i] != "*":
            used.add(i)
            res += gennext(row+1,used)
            used.remove(i)
    return res

print(gennext(0,set()))