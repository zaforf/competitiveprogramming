write = open("watermelon.py", "w").write
write("n = int(input())\n")
for i in range(1,101):
    write(("" if i==1 else"el")+"if n == "+str(i)+":\n")
    write("\tprint(\""+("YES" if i%2==0 and i>2 else "NO")+"\")\n")