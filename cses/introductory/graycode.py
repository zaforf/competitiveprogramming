fr = ["0","1"]
for i in range(1,int(input())):
    fr = ["0"+i for i in fr] + ["1"+i for i in fr[::-1]]
print("\n".join(fr))