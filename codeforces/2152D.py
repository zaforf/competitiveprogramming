for _ in range(int(input())):
	n,q = map(int,input().split())
	a = list(map(int,input().split()))
	prefix = [(0,0,0)] # special, po2, tot
	for v in a:
		special, po2, tot = prefix[-1]

		if v.bit_count() == 2 and (v // 2).bit_count() == 1:
			special += 1
		elif v.bit_count() == 1:
			po2 += 1
		tot += len(bin(v))-3
		prefix.append((special, po2, tot))


	for _ in range(q):
		l,r = map(int,input().split())
		special_l, po2_l, tot_l = prefix[l-1]
		special_r, po2_r, tot_r = prefix[r]
		special = special_r - special_l
		po2 = po2_r - po2_l
		unspecial = (r - l + 1) - special - po2
		tot = tot_r - tot_l

		print(tot + unspecial + special // 2)
