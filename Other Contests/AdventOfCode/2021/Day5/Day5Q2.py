from aocd import get_data, submit
data = get_data(day = 5, year = 2021).splitlines()
# data = '''0,9 -> 5,9
# 8,0 -> 0,8
# 9,4 -> 3,4
# 2,2 -> 2,1
# 7,0 -> 7,4
# 6,4 -> 2,0
# 0,9 -> 2,9
# 3,4 -> 1,4
# 0,0 -> 8,8
# 5,5 -> 8,2'''.splitlines()

lines = []
minX = int(1e10)
minY = int(1e10)
maxX = -int(1e10)
maxY = -int(1e10)
for l in data:
	p1, p2 = l.split(' -> ')
	p1 = list(map(int, p1.split(',')))
	p2 = list(map(int, p2.split(',')))
	p1, p2 = sorted([p1, p2])
	x1, y1 = p1
	x2, y2 = p2
	lines.append([x1, y1, x2, y2])
	minX = min(minX, x1, x2)
	minY = min(minY, y1, y2)
	maxX = max(maxX, x1, x2)
	maxY = max(maxY, y1, y2)
grid = [[0] * (maxY - minY + 1) for _ in range(maxX - minX + 1)]
for line in lines:
	x1, y1, x2, y2 = line
	if x1 == x2 or y1 == y2:
		for x in range(x1, x2 + 1):
			for y in range(y1, y2 + 1):
				grid[x - minX][y - minY] += 1
	else:
		if x1 <= x2 and y1 <= y2:
			for j in range(x2 - x1 + 1):
				grid[x1 + j - minX][y1 + j - minY] += 1
		else:
			for j in range(x2 - x1 + 1):
				grid[x1 + j - minX][y1 - j - minY] += 1
res = 0
for i in grid:
	for j in i:
    
		if j > 1:
			res += 1

print(res)
# submit(res, part = 'b', day = 5, year = 2021)
