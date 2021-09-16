x, y = map(int, input().split(','))

grid = [[0] * y for _ in range(x)]
for i in range(x):
    for j in range(y):
        grid[i][j] = i * j

print(grid)