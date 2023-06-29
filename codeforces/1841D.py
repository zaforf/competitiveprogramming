def solve():
  n = int(input())
  intervals = []
  for i in range(n):
    start, end = map(int, input().split())
    intervals.append((start, end))

  pairs = []
  for i in range(n):
    for j in range(i + 1, n):
      if max(intervals[i][0], intervals[j][0]) <= min(intervals[i][1], intervals[j][1]):
        pairs.append((min(intervals[i][0], intervals[j][0]), max(intervals[i][1], intervals[j][1])))

  pairs.sort(key=lambda pair: pair[1])

  count = 0
  last_pos = -1
  for pair in pairs:
    if pair[0] > last_pos:
      count += 1
      last_pos = pair[1]

  print( n - count * 2)

t = int(input())
for _ in range(t):
  solve()
