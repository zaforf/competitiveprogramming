S = input()
load = [0 for i in range(6)]

tot, ans = 0,0

for i in range(len(S)):
	load[0] += 1
	if S[i]=="b":
		load[1] += load[0]
		load[0] = 0
	elif S[i] == "e":
		load[2] += load[1]
		load[0] += load[5]
		ans += load[5]
		load[1]=load[5]=0
	elif S[i] == "s":
		load[4] += load[3]
		load[3] = load[2]
		load[2] = 0
	elif S[i] == "i":
		load[5] += load[4]
		load[4] = 0
	tot += ans
print(tot)
