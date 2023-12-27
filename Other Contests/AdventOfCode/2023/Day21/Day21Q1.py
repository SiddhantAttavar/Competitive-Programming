from queue import Queue
from aocd import get_data, submit
data = get_data(day = 21, year = 2023).splitlines()
# data = '''...........
# .....###.#.
# .###.##..#.
# ..#.#...#..
# ....#.#....
# .##..S####.
# .##..#...#.
# .......##..
# .##.#.####.
# .##..##.##.
# ...........'''.splitlines()

res = 0
n = len(data)
m = len(data[0])
d = [[int(1e9)] * m for _ in range(n)]
vis = [[False] * m for _ in range(n)]
q = Queue()
for i in range(n):
	for j in range(m):
		if data[i][j] == 'S':
			d[i][j] = 0
			vis[i][j] = True
			q.put((i, j))
		elif data[i][j] == '#':
			vis[i][j] = True

while not q.empty():
	x, y = q.get()
	# print(x, y, d[x][y])

	o = [
		(x - 1, y),
		(x + 1, y),
		(x, y - 1),
		(x, y + 1),
	]

	for i, j in o:
		if min(i, j) < 0 or i >= n or j >= m or vis[i][j]:
			continue
		vis[i][j] = True
		d[i][j] = d[x][y] + 1
		q.put((i, j))

for i in range(n):
	for j in range(m):
		res += d[i][j] % 2 == 0 and d[i][j] <= 64

print(res)
submit(res, part = 'a', day = 21, year = 2023)
