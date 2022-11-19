from math import inf
str1,str2 = input(),input()

edit = [[0 for i in range(len(str2)+1)] for i in range(len(str1)+1)]
for i in range(len(str1)+1):
    for j in range(len(str2)+1):
        if i==0 or j==0:
            if i==j:
                edit[i][j]=0
            elif i==0:
                edit[i][j]=edit[i][j-1]+1
            else:
                edit[i][j]=edit[i-1][j]+1
        else:
            if str1[i-1]==str2[j-1]:
                edit[i][j]=min(edit[i-1][j-1],edit[i-1][j]+1,edit[i][j-1]+1)
            else:
                edit[i][j]=min(edit[i-1][j],edit[i][j-1],edit[i-1][j-1])+1
print(edit[len(str1)][len(str2)])