red_score = 0
yellow_score = 0

button = (144,84)

for _ in range(10):
	red = [*map(int,input().split())]
	yellow = [*map(int,input().split())]

	red = [(red[i],red[i+1]) for i in range(1,len(red),2)]
	yellow = [(yellow[i],yellow[i+1]) for i in range(1,len(yellow),2)]

	# find closest stone to button
	red_closest = min((x-button[0])**2 + (y-button[1])**2 for x,y in red) if red else float('inf')
	yellow_closest = min((x-button[0])**2 + (y-button[1])**2 for x,y in yellow) if yellow else float('inf')

	if red_closest < yellow_closest:
		red_score += sum(1 for x,y in red if (x-button[0])**2 + (y-button[1])**2 < yellow_closest)
	elif yellow_closest < red_closest:
		yellow_score += sum(1 for x,y in yellow if (x-button[0])**2 + (y-button[1])**2 < red_closest)

print(red_score,yellow_score)