read = open("advent2.in", "r").readline

ans = 0
while True:
    inp = read()
    if inp=="end":
        break
    a,b = inp.split()
    t = {"A":["Y","X","Z"],"B":["Z","Y","X"],"C":["X","Z","Y"]}
    s = ["X","Y","Z"]
    ans += s.index(b)*3+s.index(t[a][2-s.index(b)])+1
print(ans)