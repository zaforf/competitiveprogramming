grid = []

def checkwin():
  wins = [(0, 1, 2), (3, 4, 5), (6, 7, 8), (0, 3, 6), (1, 4, 7), (2, 5, 8), (0, 4, 8), (2, 4, 6)]
  for a,b,c in wins:
    if grid[a]==grid[b] and grid[b]==grid[c] and grid[c]!=".":
      print(grid[a])
      return
  print("DRAW")
  
for _ in range(int(input())):
  grid = input()+input()+input()
  checkwin()