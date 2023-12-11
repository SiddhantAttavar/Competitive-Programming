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
# data = '''.F----7F7F7F7F-7....
# .|F--7||||||||FJ....
# .||.FJ||||||||L7....
# FJL7L7LJLJ||LJ.L-7..
# L--J.L7...LJS7F-7L7.
# ....F-J..F7FJ|L7L7L7
# ....L7.F7||L7|.L7L7|
# .....|FJLJ|FJ|F7|.LJ
# ....FJL-7.||.||||...
# ....L---J.LJ.LJLJ...'''.splitlines()
# data = '''FF7FSF7F7F7F7F7F---7
# L|LJ||||||||||||F--J
# FL-7LJLJ||||||LJL-77
# F--JF--7||LJLJ7F7FJ-
# L---JF-JLJ.||-FJLJJ7
# |F|F-JF---7F7-L7L|7|
# |FFJF7L7F-JF7|JL---7
# 7-L-JL7||F7|L7F-7F7|
# L.L7LFJ|||||FJL7||LJ
# L7JLJL-JLJLJL--JLJ.L'''.splitlines()

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
		res = (x, y)
		# break

b = [[False] * m for _ in range(n)]
vis = [[False] * m for _ in range(n)]
x, y = res
vis[x][y] = True
q.put((x, y))
# print(x, y)
while not q.empty():
	x, y = q.get()
	# print(x, y)
	b[x][y] = True
	# print(x, y)

	for i, j in [(a + x, b + y) for a, b in d[data[x][y]]]:
		if not vis[i][j] and data[i][j] != '.':
			vis[i][j] = True
			q.put((i, j))
			# break

# print(sum([sum(i) for i in b]))
# print(x, y)
x = y = -1
for i in range(n):
	for j in range(m):
		if data[i][j] == 'S':
			x = i
			y = j
			break
	if x != -1:
		break

# print(x, y)
for k, l in d.items():
	if k == '.':
		continue
	for i, j in l:
		if (x, y) not in [(a + i + x, b + j + y) for a, b in d[data[i + x][j + y]]]:
			break
	else:
		data[x] = data[x][:y] + k + data[x][y + 1:]
		break
# print(*data, sep = '\n')

v = [[True] * m for _ in range(n)]
q.put((0, 0))
vis = [[False] * m for _ in range(n)]
vis[0][0] = True
while not q.empty():
	x, y = q.get()
	# print(x, y)
	v[x][y] = False

	for i, j in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]:
		if min(i, j) >= 0 and i < n and j < m and not vis[i][j] and not b[i][j]:
			vis[i][j] = True
			q.put((i, j))

# for i in v:
# 	print(*map(int ,i))
# print()
# for i in b:
# 	print(*map(int ,i))
# print()

res = 0
temp = []
for i in range(n):
	x = False
	c = ' '
	for j in range(m):
		if b[i][j]:
			if data[i][j] == '|':
				x = not x
			elif data[i][j] == 'L':
				c = 'L'
			elif data[i][j] == 'F':
				c = 'F'
			elif data[i][j] == 'J' and c == 'F':
				x = not x
			elif data[i][j] == '7' and c == 'L':
				x = not x
			# print('0 ', end = '')
		else:
			temp.append((i, j, x))
			res += x
			# print(int(x), end = ' ')
	# print()
# for i, j, x in temp:
# 	print(i, j, x)
print(res)
# print(x, y)
# print(sum([sum(i) for i in v]) - sum([sum(i) for i in b]))
submit(res, part = 'b', day = 10, year = 2023)
