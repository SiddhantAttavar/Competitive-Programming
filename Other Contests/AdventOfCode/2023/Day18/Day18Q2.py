from sys import setrecursionlimit
setrecursionlimit(int(1e6))
from aocd import get_data, submit
data = get_data(day = 18, year = 2023).splitlines()
data = '''R 6 (#70c710)
D 5 (#0dc571)
L 2 (#5713f0)
D 2 (#d2c081)
R 2 (#59c680)
D 2 (#411b91)
L 5 (#8ceee2)
U 2 (#caa173)
L 1 (#1b58a2)
U 2 (#caa171)
R 2 (#7807d2)
U 3 (#a77fa3)
L 2 (#015232)
U 2 (#7a21e3)'''.splitlines()

res = 0
x, y = 0, 0
l = []
for s in data:
	a, b, c = s.split()
	l.append((int(c[-2]), int(c[2:-2], 16), int(b)))

d = [
	(0, 1),
	(1, 0),
	(0, -1),
	(-1, 0),
]
v = {(0, 0)}
for a, b, c in l:
	for i in range(b):
		x += d[a][0]
		y += d[a][1]
		v.add((x, y))

res = len(v)

x_min = x_max = y_min = y_max = 0
for x, y in v:
	x_min = min(x, x_min)
	x_max = max(x, x_max)
	y_min = min(y, y_min)
	y_max = max(y, y_max)

t = 0
def dfs(x, y):
	global t
	# print(x, y, t, x_min, x_max, y_min, y_max)
	t += 1
	v.add((x, y))

	for s in range(4):
		i, j = x + d[s][0], y + d[s][1]
		# print(i, j, x_min, x_max, y_min, y_max)
		if (i >= x_min) and (j >= y_min) and (i <= x_max) and (j <= y_max) and ((i, j) not in v):
			dfs(i, j)

x_min -= 1
y_min -= 1
x_max += 1
y_max += 1
print(x_min, x_max, y_min, y_max)
# dfs(x_min, y_min)

# print(sorted(v))
# print(len(v))

res += ((x_max - x_min + 1) * (y_max - y_min + 1) - len(v))

print(res)
# submit(res, part = 'b', day = 18, year = 2023)
