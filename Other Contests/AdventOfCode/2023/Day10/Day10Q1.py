from queue import Queue
from aocd import get_data, submit
data = get_data(day = 10, year = 2023).splitlines()
# data = '''.....
# .S-7.
# .|.|.
# .L-J.
# .....'''.splitlines()
# data = '''..F7.
# .FJ|.
# SJ.L7
# |F--J
# LJ...'''.splitlines()

res = 0
data = ['.' + i + '.' for i in data]
data = ['.' * len(data[0])] + data + ['.' * len(data[0])]
d = {
	'.': [],
	'|': [(-1, 0), (1, 0)],
	'-': [(0, -1), (0, 1)],
	'L': [(-1, 0), (0, 1)],
	'J': [(-1, 0), (0, -1)],
	'7': [(0, -1), (1, 0)],
	'F': [(0, 1), (1, 0)],
	'S': [],
}

x = y = -1
n = len(data)
m = len(data[0])
graph = [[[] for _ in range(m)] for _ in range(n)]
rev_graph = [[[] for _ in range(m)] for _ in range(n)]
for i in range(n):
	for j, c in enumerate(data[i]):
		if c == 'S':
			x = i
			y = j
			break
	if x != -1:
		break

q = Queue()
l = [[-1] * m for _ in range(n)]
l[x][y] = 0
for i, j in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]:
	if data[i][j] != '.' and (x, y) in [(a + i, b + j) for a, b in d[data[i][j]]]:
		l[i][j] = 1
		q.put((i, j))

# print(x, y)
res = -1
while not q.empty():
	x, y = q.get()
	# print(x, y, l[x][y])
	# print(x, y)

	for i, j in [(a + x, b + y) for a, b in d[data[x][y]]]:
		if l[i][j] == -1 and data[i][j] != '.':
			l[i][j] = l[x][y] + 1
			q.put((i, j))
			break
	else:
		res = l[x][y]
		# break

# for i in l:
# 	print(*i)
# print(res)
# print(x, y)
print(res)
submit(res, part = 'a', day = 10, year = 2023)
