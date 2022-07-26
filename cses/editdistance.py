from math import inf
str1,str2 = input(),input()

edit = [[1 for i in range(len(str2))] for i in range(len(str1))]
for i in range(len(str1)):
    for j in range(len(str2)):
        if i==j and i==0: 
            edit[i][j] = 0 if str1[i]==str2[j] else 1
            continue
        edit[i][j] = inf
        if i>0: edit[i][j] = min(edit[i][j],edit[i-1][j]+1)
        if j>0: edit[i][j] = min(edit[i][j],edit[i][j-1]+1)
        if i>0 and j>0: edit[i][j] = min(edit[i][j],edit[i-1][j-1]+(0 if str1[i]==str2[j] else 1))

print(edit[len(str1)-1][len(str2)-1])