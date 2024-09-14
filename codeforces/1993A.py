for _ in range(int(input())):
	n = int(input())
	s = input()
	print(sum(min(i,n) for i in [s.count('A'),s.count('B'),s.count('C'),s.count('D')]))