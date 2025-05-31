s=l=0
for _ in[0]*int(input()):x=int(input());s+=(x>l)*(x-l+1);l=x
print(s+1)