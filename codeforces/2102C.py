def spiral_grid(n):
    grid = [[0 for _ in range(n)] for _ in range(n)]
    top, bottom, left, right = 0, n - 1, 0, n - 1
    direction = 0
    num = 1

    while top <= bottom and left <= right:
        if direction == 0:
            for i in range(left, right + 1):
                grid[top][i] = n*n - num
                num += 1
            top += 1
        elif direction == 1:
            for i in range(top, bottom + 1):
                grid[i][right] = n*n - num
                num += 1
            right -= 1
        elif direction == 2:
            for i in range(right, left - 1, -1):
                grid[bottom][i] = n*n - num
                num += 1
            bottom -= 1
        elif direction == 3:
            for i in range(bottom, top - 1, -1):
                grid[i][left] = n*n - num
                num += 1
            left += 1
        direction = (direction + 1) % 4
    return grid

for _ in range(int(input())):
    n = int(input())
    spiral = spiral_grid(n)
    for row in spiral:
        print(" ".join(map(str,row)))