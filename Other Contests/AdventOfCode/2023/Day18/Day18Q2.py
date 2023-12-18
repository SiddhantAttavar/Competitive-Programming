from queue import Queue
from sys import setrecursionlimit
setrecursionlimit(int(1e6))
from aocd import get_data, submit
data = get_data(day = 18, year = 2023).splitlines()
# data = '''R 6 (#70c710)
# D 5 (#0dc571)
# L 2 (#5713f0)
# D 2 (#d2c081)
# R 2 (#59c680)
# D 2 (#411b91)
# L 5 (#8ceee2)
# U 2 (#caa173)
# L 1 (#1b58a2)
# U 2 (#caa171)
# R 2 (#7807d2)
# U 3 (#a77fa3)
# L 2 (#015232)
# U 2 (#7a21e3)'''.splitlines()

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
v = []
res = 0
for a, b, c in l:
	res += b
	x += d[a][0] * b
	y += d[a][1] * b
	v.append((x, y))

c = ((v[0][0] + v[-1][0]) * (v[0][1] - v[-1][1])) / 2
for i in range(0, len(v) - 1):
	c += ((v[i + 1][0] + v[i][0]) * (v[i + 1][1] - v[i][1])) / 2

res = int(abs(c) + (res + 2) // 2)
print(res)
submit(res, part = 'b', day = 18, year = 2023)
