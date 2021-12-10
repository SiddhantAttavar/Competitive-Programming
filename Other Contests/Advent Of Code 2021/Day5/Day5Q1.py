from aocd import get_data, submit
data = get_data(day = 5, year = 2021).splitlines()

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
				
res = 0
for i in grid:
	for j in i:
    
		if j > 1:
			res += 1

print(res)
#submit(res, part = 'a', day = 5, year = 2021)
