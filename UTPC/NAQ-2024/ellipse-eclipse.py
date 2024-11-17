from math import sqrt

x1,y1,x2,y2,a = map(int,input().split())

x1,x2 = min(x1,x2),max(x1,x2)
y1,y2 = min(y1,y2),max(y1,y2)

cx,cy = (x1+x2)/2,(y1+y2)/2
dx,dy = x2-cx,y2-cy

if (dx==0 and dy == 0):
	print(cx-a/2,cy-a/2,cx+a/2,cy+a/2)
	quit()

scale = (a/2)/sqrt(dx**2+dy**2)
dx *= scale
dy *= scale
ax = dx + cx
ay = dy + cy

dx,dy = x2-cx,y2-cy
b = sqrt((a/2)**2-(dx**2+dy**2))

scale = b/sqrt(dx**2+dy**2)
dx *= scale
dy *= scale
bx = -dy + cx
by = dx + cy

print(cx - sqrt((ax-cx)**2+(bx-cx)**2),end=" ")
print(cy - sqrt((ay-cy)**2+(by-cy)**2),end=" ")
print(cx + sqrt((ax-cx)**2+(bx-cx)**2),end=" ")
print(cy + sqrt((ay-cy)**2+(by-cy)**2))