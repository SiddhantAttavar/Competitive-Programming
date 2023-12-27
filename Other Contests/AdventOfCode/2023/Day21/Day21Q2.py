from queue import Queue
from aocd import get_data, submit
data = get_data(day = 21, year = 2023).splitlines()
data = '''...........
.....###.#.
.###.##..#.
..#.#...#..
....#.#....
.##..S####.
.##..#...#.
.......##..
.##.#.####.
.##..##.##.
...........'''.splitlines()

res = 0
n = len(data)
m = len(data[0])
vis = [[[False, False] for _ in range(m)] for _ in range(n)]
d = [[[int(1e9), int(1e9)] for _ in range(m)] for _ in range(n)]
q = Queue()
for i in range(n):
	for j in range(m):
		if data[i][j] == 'S':
			d[i][j][0] = 0
			vis[i][j][0] = True
			q.put((i, j, 0))
		elif data[i][j] == '#':
			vis[i][j][0] = True
			vis[i][j][1] = True

while not q.empty():
	x, y, z = q.get()
	# print(x, y, d[x][y])

	o = [
		(x - 1, y),
		(x + 1, y),
		(x, y - 1),
		(x, y + 1),
	]

	for i, j in o:
		i = (i + n) % n
		j = (j + m) % m
		if vis[i][j][not z]:
			continue
		vis[i][j][not z] = True
		d[i][j][not z] = d[x][y][z] + 1
		q.put((i, j, not z))

t = 50
for i in range(n):
	for j in range(m):
		# res += d[i][j][t % 2] <= t
		if d[i][j][t % 2] <= t:
			x = (t - d[i][j][t % 2]) // 11
			print(x)
			res += 2 * x * (x + 1) + 1

print(res)
# submit(res, part = 'b', day = 21, year = 2023)
