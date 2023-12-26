boxes = []
for _ in range(int(input())):
	a,b,c = map(int,input().split())
	boxes.append([a*b*c,a,b,c])
boxes.sort()
ok = True
a,b,c = 0,0,0

def works(x,y,z):
	return x>a and y>b and z>c
	
for i in range(len(boxes)-1):
	a,b,c = boxes[i][1],boxes[i][2],boxes[i][3]
	x,y,z = boxes[i+1][1],boxes[i+1][2],boxes[i+1][3]
	if works(x,y,z) or works(x,z,y) or works(y,x,z) or works(y,z,x) or works(z,x,y) or works(z,y,x):
		continue
	else:
		ok = False
		print("NO")
		break
if ok:
	print("YES")