from aocd import get_data, submit
data = get_data(day = 13, year = 2021).splitlines()
# data = '''6,10
# 0,14
# 9,10
# 0,3
# 10,4
# 4,11
# 6,0
# 6,12
# 4,1
# 0,13
# 10,12
# 3,4
# 3,0
# 8,4
# 1,10
# 2,14
# 8,10
# 9,0

# fold along y=7
# fold along x=5'''.splitlines()

p = []
f = True
for l in data:
	if not l:
		f = False
	elif f:
		p.append(tuple(map(int, l.split(','))))
	else:
		n = []
		a, b = l.split('=')
		b = int(b)
		for x, y in p:
			if a[-1] == 'x' and x > b:
				n.append((b - (x - b), y))
			elif a[-1] == 'y' and y > b:
				n.append((x, b - (y - b)))
			else:
				n.append((x, y))
		p = list(set(n))

grid = [['.'] * 80 for _ in range(10)]
for x, y in p:
	grid[y][x] = '#'

for row in grid:
	print(*row, sep = '')

# submit(res, part = 'b', day = 13, year = 2021)
